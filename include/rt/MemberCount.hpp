#pragma once

// C++
#include <cstdint>
#include <type_traits>

// rt
#include <rt/Traits.hpp>

namespace rt
{
    namespace detail
    {
        template <typename... Ts>
        struct Overloaded : Ts... { using Ts::operator()...; };

        template <typename... Ts>
        Overloaded(Ts...) -> Overloaded<Ts...>;

        template <typename T>
        consteval size_t get_member_count() noexcept
        {
            if constexpr (std::is_empty_v<T>) return 0;

            using Dispatcher_t = decltype(Overloaded
            {
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0 ] = x;
                    Tag<1>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1 ] = x;
                    Tag<2>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2 ] = x;
                    Tag<3>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3 ] = x;
                    Tag<4>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4 ] = x;
                    Tag<5>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4, _5 ] = x;
                    Tag<6>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4, _5, _6 ] = x;
                    Tag<7>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4, _5, _6, _7 ] = x;
                    Tag<8>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4, _5, _6, _7, _8 ] = x;
                    Tag<9>{}; })) { return {}; },
                [](auto&& x) -> decltype(({ [[maybe_unused]] auto&& [ _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 ] = x;
                    Tag<10>{}; })) { return {}; },
            }
            (std::declval<T>()));

            return Dispatcher_t{}.value;
        }
    }

    template <typename T>
    consteval size_t get_member_count() noexcept
    {
        return detail::get_member_count<T>();
    }
}
