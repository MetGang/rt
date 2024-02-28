#pragma once

// rt
#include <rt/MemberCount.hpp>
#include <rt/Traits.hpp>
#include <rt/Visit.hpp>
#include <rt/Util.hpp>

#define RT_TCONV_ARG(__n) std::forward<ExtentlessCopyReference_t<T ## __n, TSrc>>(deep_dispatch(&t ## __n, Is ## __n))...

namespace rt
{
    namespace detail
    {
        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&&, Tag<0>)
        {
            return TDst<>{};
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<1>)
        {
            auto&& [ t0 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);

            using PureT0 = std::remove_cv_t<T0>;

            return [&]
                <size_t... Is0>
                (std::index_sequence<Is0...>)
            {
                return TDst<PureT0>{
                    RT_TCONV_ARG(0)
                };
            }
            (ArrayFlatIndices_v<T0>);
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<2>)
        {
            auto&& [ t0, t1 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;

            return [&]
                <size_t... Is0, size_t... Is1>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>)
            {
                return TDst<PureT0, PureT1>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>);
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<3>)
        {
            auto&& [ t0, t1, t2 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>)
            {
                return TDst<PureT0, PureT1, PureT2>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>);
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<4>)
        {
            auto&& [ t0, t1, t2, t3 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>);
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<5>)
        {
            auto&& [ t0, t1, t2, t3, t4 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>);
        }

        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<6>)
        {
            auto&& [ t0, t1, t2, t3, t4, t5 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);
            using T5 = decltype(t5);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;
            using PureT5 = std::remove_cv_t<T5>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4, size_t... Is5>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>, std::index_sequence<Is5...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4, PureT5>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4), RT_TCONV_ARG(5)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>, ArrayFlatIndices_v<T5>);
        }


        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<7>)
        {
            auto&& [ t0, t1, t2, t3, t4, t5, t6 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);
            using T5 = decltype(t5);
            using T6 = decltype(t6);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;
            using PureT5 = std::remove_cv_t<T5>;
            using PureT6 = std::remove_cv_t<T6>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4, size_t... Is5, size_t... Is6>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>, std::index_sequence<Is5...>, std::index_sequence<Is6...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4, PureT5, PureT6>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4), RT_TCONV_ARG(5), RT_TCONV_ARG(6)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>, ArrayFlatIndices_v<T5>, ArrayFlatIndices_v<T6>);
        }


        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<8>)
        {
            auto&& [ t0, t1, t2, t3, t4, t5, t6, t7 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);
            using T5 = decltype(t5);
            using T6 = decltype(t6);
            using T7 = decltype(t7);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;
            using PureT5 = std::remove_cv_t<T5>;
            using PureT6 = std::remove_cv_t<T6>;
            using PureT7 = std::remove_cv_t<T7>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4, size_t... Is5, size_t... Is6, size_t... Is7>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>, std::index_sequence<Is5...>, std::index_sequence<Is6...>, std::index_sequence<Is7...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4, PureT5, PureT6, PureT7>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4), RT_TCONV_ARG(5), RT_TCONV_ARG(6), RT_TCONV_ARG(7)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>, ArrayFlatIndices_v<T5>, ArrayFlatIndices_v<T6>, ArrayFlatIndices_v<T7>);
        }


        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<9>)
        {
            auto&& [ t0, t1, t2, t3, t4, t5, t6, t7, t8 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);
            using T5 = decltype(t5);
            using T6 = decltype(t6);
            using T7 = decltype(t7);
            using T8 = decltype(t8);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;
            using PureT5 = std::remove_cv_t<T5>;
            using PureT6 = std::remove_cv_t<T6>;
            using PureT7 = std::remove_cv_t<T7>;
            using PureT8 = std::remove_cv_t<T8>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4, size_t... Is5, size_t... Is6, size_t... Is7, size_t... Is8>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>, std::index_sequence<Is5...>, std::index_sequence<Is6...>, std::index_sequence<Is7...>, std::index_sequence<Is8...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4, PureT5, PureT6, PureT7, PureT8>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4), RT_TCONV_ARG(5), RT_TCONV_ARG(6), RT_TCONV_ARG(7), RT_TCONV_ARG(8)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>, ArrayFlatIndices_v<T5>, ArrayFlatIndices_v<T6>, ArrayFlatIndices_v<T7>, ArrayFlatIndices_v<T8>);
        }


        template <template <typename...> typename TDst, typename TSrc>
        constexpr auto tconvert(TSrc&& src, Tag<10>)
        {
            auto&& [ t0, t1, t2, t3, t4, t5, t6, t7, t8, t9 ] = std::forward<TSrc>(src);

            using T0 = decltype(t0);
            using T1 = decltype(t1);
            using T2 = decltype(t2);
            using T3 = decltype(t3);
            using T4 = decltype(t4);
            using T5 = decltype(t5);
            using T6 = decltype(t6);
            using T7 = decltype(t7);
            using T8 = decltype(t8);
            using T9 = decltype(t9);

            using PureT0 = std::remove_cv_t<T0>;
            using PureT1 = std::remove_cv_t<T1>;
            using PureT2 = std::remove_cv_t<T2>;
            using PureT3 = std::remove_cv_t<T3>;
            using PureT4 = std::remove_cv_t<T4>;
            using PureT5 = std::remove_cv_t<T5>;
            using PureT6 = std::remove_cv_t<T6>;
            using PureT7 = std::remove_cv_t<T7>;
            using PureT8 = std::remove_cv_t<T8>;
            using PureT9 = std::remove_cv_t<T9>;

            return [&]
                <size_t... Is0, size_t... Is1, size_t... Is2, size_t... Is3, size_t... Is4, size_t... Is5, size_t... Is6, size_t... Is7, size_t... Is8, size_t... Is9>
                (std::index_sequence<Is0...>, std::index_sequence<Is1...>, std::index_sequence<Is2...>, std::index_sequence<Is3...>, std::index_sequence<Is4...>, std::index_sequence<Is5...>, std::index_sequence<Is6...>, std::index_sequence<Is7...>, std::index_sequence<Is8...>, std::index_sequence<Is9...>)
            {
                return TDst<PureT0, PureT1, PureT2, PureT3, PureT4, PureT5, PureT6, PureT7, PureT8, PureT9>{
                    RT_TCONV_ARG(0), RT_TCONV_ARG(1), RT_TCONV_ARG(2), RT_TCONV_ARG(3), RT_TCONV_ARG(4), RT_TCONV_ARG(5), RT_TCONV_ARG(6), RT_TCONV_ARG(7), RT_TCONV_ARG(8), RT_TCONV_ARG(9)
                };
            }
            (ArrayFlatIndices_v<T0>, ArrayFlatIndices_v<T1>, ArrayFlatIndices_v<T2>, ArrayFlatIndices_v<T3>, ArrayFlatIndices_v<T4>, ArrayFlatIndices_v<T5>, ArrayFlatIndices_v<T6>, ArrayFlatIndices_v<T7>, ArrayFlatIndices_v<T8>, ArrayFlatIndices_v<T9>);
        }
    }

    template <template <typename...> typename TDst, typename TSrc>
    constexpr auto tconvert(TSrc&& src)
    {
        constexpr size_t count = get_member_count<TSrc>();

        return detail::tconvert<TDst>(std::forward<TSrc>(src), Tag<count>{});
    }
}

#undef RT_TCONV_ARG
