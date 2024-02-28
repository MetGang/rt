#pragma once

// C++
#include <bits/utility.h>
#include <functional>

namespace rt
{
    template <typename... Ts>
    struct Tuple;

    template <>
    struct Tuple<>
    {
        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0>
    struct Tuple<T0>
    {
        T0 t0;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1>
    struct Tuple<T0, T1>
    {
        T0 t0; T1 t1;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2>
    struct Tuple<T0, T1, T2>
    {
        T0 t0; T1 t1; T2 t2;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3>
    struct Tuple<T0, T1, T2, T3>
    {
        T0 t0; T1 t1; T2 t2; T3 t3;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    struct Tuple<T0, T1, T2, T3, T4>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct Tuple<T0, T1, T2, T3, T4, T5>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4; T5 t5;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    struct Tuple<T0, T1, T2, T3, T4, T5, T6>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4; T5 t5; T6 t6;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    struct Tuple<T0, T1, T2, T3, T4, T5, T6, T7>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4; T5 t5; T6 t6; T7 t7;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    struct Tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4; T5 t5; T6 t6; T7 t7; T8 t8;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    struct Tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>
    {
        T0 t0; T1 t1; T2 t2; T3 t3; T4 t4; T5 t5; T6 t6; T7 t7; T8 t8; T9 t9;

        constexpr auto operator<=>(Tuple const&) const = default;
    };

    template <typename... Ts>
    Tuple(Ts...) -> Tuple<Ts...>;

    template <typename... Args>
    constexpr Tuple<std::decay_t<Args>...> make_tuple(Args&&... args)
    {
        return { std::forward<Args>(args)... };
    }

    template <typename... Args>
    constexpr Tuple<Args&&...> forward_as_tuple(Args&&... args)
    {
        return { std::forward<Args>(args)... };
    }

    namespace detail
    {
        template <std::size_t I, typename T>
        constexpr auto get_member_ptr() noexcept
        {
            if constexpr (I == 0) return &T::t0;
            else if constexpr (I == 1) return &T::t1;
            else if constexpr (I == 2) return &T::t2;
            else if constexpr (I == 3) return &T::t3;
            else if constexpr (I == 4) return &T::t4;
            else if constexpr (I == 5) return &T::t5;
            else if constexpr (I == 6) return &T::t6;
            else if constexpr (I == 7) return &T::t7;
            else if constexpr (I == 8) return &T::t8;
            else if constexpr (I == 9) return &T::t9;
        }

        template <std::size_t I, typename T>
        constexpr decltype(auto) get(T&& t) noexcept
        {
            auto const member = get_member_ptr<I, std::remove_cvref_t<T>>();

            return std::forward<T>(t).*member;
        }

        template <typename T, typename F, std::size_t... Is>
        constexpr decltype(auto) apply(T&& t, F&& f, std::index_sequence<Is...>)
        {
            return std::invoke(std::forward<F>(f), get<Is>(std::forward<T>(t))...);
        }

        template <typename T, typename F, std::size_t... Is>
        constexpr auto map(T&& t, F&& f, std::index_sequence<Is...>)
        {
            return make_tuple(std::invoke(std::forward<F>(f), get<Is>(std::forward<T>(t)))...);
        }

        template <typename S, typename T, std::size_t... Is>
        constexpr S make_from_tuple(T&& t, std::index_sequence<Is...>)
        {
            return S(get<Is>(std::forward<T>(t))...);
        }
    }

    template <std::size_t vIdx, typename... Ts>
    constexpr decltype(auto) get(Tuple<Ts...>& tuple) noexcept
    {
        return detail::get<vIdx>(tuple);
    }

    template <std::size_t vIdx, typename... Ts>
    constexpr decltype(auto) get(Tuple<Ts...> const& tuple) noexcept
    {
        return detail::get<vIdx>(tuple);
    }

    template <std::size_t vIdx, typename... Ts>
    constexpr decltype(auto) get(Tuple<Ts...>&& tuple) noexcept
    {
        return detail::get<vIdx>(std::move(tuple));
    }

    template <std::size_t vIdx, typename... Ts>
    constexpr decltype(auto) get(Tuple<Ts...> const&& tuple) noexcept
    {
        return detail::get<vIdx>(std::move(tuple));
    }

    template <typename F, typename... Ts>
    constexpr decltype(auto) apply(Tuple<Ts...>& tuple, F&& f)
    {
        return detail::apply(tuple, std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr decltype(auto) apply(Tuple<Ts...> const& tuple, F&& f)
    {
        return detail::apply(tuple, std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr decltype(auto) apply(Tuple<Ts...>&& tuple, F&& f)
    {
        return detail::apply(std::move(tuple), std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr decltype(auto) apply(Tuple<Ts...> const&& tuple, F&& f)
    {
        return detail::apply(std::move(tuple), std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr auto map(Tuple<Ts...>& tuple, F&& f)
    {
        return detail::map(tuple, std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr auto map(Tuple<Ts...> const& tuple, F&& f)
    {
        return detail::map(tuple, std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr auto map(Tuple<Ts...>&& tuple, F&& f)
    {
        return detail::map(std::move(tuple), std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename F, typename... Ts>
    constexpr auto map(Tuple<Ts...> const&& tuple, F&& f)
    {
        return detail::map(std::move(tuple), std::forward<F>(f), std::index_sequence_for<Ts...>{});
    }

    template <typename S, typename... Ts>
    constexpr S make_from_tuple(Tuple<Ts...>& tuple)
    {
        return detail::make_from_tuple<S>(tuple, std::index_sequence_for<Ts...>{});
    }

    template <typename S, typename... Ts>
    constexpr S make_from_tuple(Tuple<Ts...> const& tuple)
    {
        return detail::make_from_tuple<S>(tuple, std::index_sequence_for<Ts...>{});
    }

    template <typename S, typename... Ts>
    constexpr S make_from_tuple(Tuple<Ts...>&& tuple)
    {
        return detail::make_from_tuple<S>(std::move(tuple), std::index_sequence_for<Ts...>{});
    }

    template <typename S, typename... Ts>
    constexpr S make_from_tuple(Tuple<Ts...> const&& tuple)
    {
        return detail::make_from_tuple<S>(std::move(tuple), std::index_sequence_for<Ts...>{});
    }

    template <typename... Ts>
    struct Size;

    template <typename... Ts>
    struct Size<Tuple<Ts...>> : std::integral_constant<size_t, sizeof...(Ts)> {};

    template <typename TTuple>
    inline constexpr auto Size_v = Size<std::remove_cv_t<TTuple>>::value;
}
