#pragma once

// C++
#include <array>
#include <source_location>
#include <string_view>

// rt
#include <rt/Visit.hpp>

#define RT_FWD(__expr) std::forward<decltype(__expr)>(__expr)

struct RT_STRUCT { RT_STRUCT* MEMBER; enum class ENUM { VALUE }; };

namespace rt
{
    namespace detail
    {
        template <typename T>
        consteval std::string_view fn_name() noexcept
        {
            return std::source_location::current().function_name();
        }

        template <auto V>
        consteval std::string_view fn_name() noexcept
        {
            return std::source_location::current().function_name();
        }

        template <typename T>
        extern T const lift = {};

        template <typename T>
        struct Ptr { T const* value; };

        template <typename T>
        Ptr(T const*) -> Ptr<T>;

        template<std::size_t N> [[nodiscard]] constexpr decltype(auto) nth_pack_element(auto&&... args) noexcept {
            return [&]<auto... Ns>(std::index_sequence<Ns...>) -> decltype(auto) {
                return [](decltype((const void*)Ns)..., auto* nth, auto*...) -> decltype(auto) { return *nth; }(&args...);
            }(std::make_index_sequence<N>{});
        }
    }

    template <typename T>
    consteval std::string_view get_type_name() noexcept
    {
        constexpr auto rt_name = detail::fn_name<RT_STRUCT>();
        constexpr auto index = rt_name.find("RT_STRUCT");
        constexpr auto excess = std::size(rt_name.substr(index + std::size("RT_STRUCT") - 1));

        constexpr auto name = detail::fn_name<T>();
        constexpr auto full = name.substr(index, std::size(name) - index - excess);

        return full.substr(full.find_last_of("::") + 1);
    }

    template <typename T, size_t vIdx>
    consteval std::string_view get_nth_member_name() noexcept
    {
        constexpr auto rt_name = detail::fn_name<detail::Ptr{&detail::lift<RT_STRUCT>.MEMBER}>();
        constexpr auto beginning = rt_name[rt_name.find("MEMBER") - 1];
        constexpr auto ending = rt_name.substr(rt_name.find("MEMBER") + std::size("MEMBER") - 1);

        constexpr std::string_view name = detail::fn_name<visit([](auto&&... args) { return detail::Ptr{&detail::nth_pack_element<vIdx>(RT_FWD(args)...)}; }, detail::lift<T>)>();
        constexpr std::string_view tmp = name.substr(0, name.find(ending));
        constexpr std::string_view full = tmp.substr(tmp.find_last_of(beginning) + 1);

        return full.substr(full.find_last_of("::") + 1);;
    }

    template <typename E, size_t vMin, size_t vMax>
    consteval std::string_view get_enum_name(E e) noexcept
    {
        constexpr auto rt_name = detail::fn_name<RT_STRUCT::ENUM::VALUE>();
        constexpr auto index = rt_name[rt_name.find("RT_STRUCT::ENUM::VALUE") - 1];
        constexpr auto end = rt_name.substr(rt_name.find("RT_STRUCT::ENUM::VALUE") + std::size(std::string_view{"RT_STRUCT::ENUM::VALUE"}));

        std::array<std::string_view, vMax - vMin + 1> names = {};

        [&] <size_t... Is> (std::index_sequence<Is...>) {
            ([&]{
                constexpr auto name = detail::fn_name<static_cast<E>(Is + vMin)>();
                constexpr auto full_enum_name = name.substr(0, name.find(end));
                names[Is] = full_enum_name.substr(full_enum_name.find_last_of(index) + 1);
                names[Is] = names[Is].substr(names[Is].find_last_of("::") + 1);
            }(), ...);
        }(std::make_index_sequence<std::size(names)>{});

        return names[static_cast<size_t>(e) - vMin];
    }
}

#undef RT_CONV_ARG
