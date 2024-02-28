#pragma once

// C++
#include <functional>

// rt
#include <rt/MemberCount.hpp>
#include <rt/Traits.hpp>

#define RT_FWD(__expr) std::forward<decltype(__expr)>(__expr)

namespace rt
{
    namespace detail
    {
        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&&, Tag<0>)
        {
            return std::invoke(RT_FWD(f));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<1>)
        {
            auto&& [ _0 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<2>)
        {
            auto&& [ _0, _1 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<3>)
        {
            auto&& [ _0, _1, _2 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<4>)
        {
            auto&& [ _0, _1, _2, _3 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<5>)
        {
            auto&& [ _0, _1, _2, _3, _4 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<6>)
        {
            auto&& [ _0, _1, _2, _3, _4, _5 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4), RT_FWD(_5));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<7>)
        {
            auto&& [ _0, _1, _2, _3, _4, _5, _6 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4), RT_FWD(_5), RT_FWD(_6));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<8>)
        {
            auto&& [ _0, _1, _2, _3, _4, _5, _6, _7 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4), RT_FWD(_5), RT_FWD(_6), RT_FWD(_7));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<9>)
        {
            auto&& [ _0, _1, _2, _3, _4, _5, _6, _7, _8 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4), RT_FWD(_5), RT_FWD(_6), RT_FWD(_7), RT_FWD(_8));
        }

        template <typename F, typename T>
        [[nodiscard]] constexpr decltype(auto) visit(F&& f, T&& t, Tag<10>)
        {
            auto&& [ _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 ] = RT_FWD(t);

            return std::invoke(RT_FWD(f), RT_FWD(_0), RT_FWD(_1), RT_FWD(_2), RT_FWD(_3), RT_FWD(_4), RT_FWD(_5), RT_FWD(_6), RT_FWD(_7), RT_FWD(_8), RT_FWD(_9));
        }
    }

    template <typename Callable, typename TSrc>
    constexpr decltype(auto) visit(Callable&& callable, TSrc&& src)
    {
        constexpr size_t count = get_member_count<TSrc>();

        return detail::visit(std::forward<Callable>(callable), std::forward<TSrc>(src), Tag<count>{});
    }
}

#undef RT_FWD
