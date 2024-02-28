#pragma once

// rt
#include <rt/Traits.hpp>

namespace rt
{
    namespace detail
    {
        template <size_t I, size_t... Is>
        constexpr auto get_deep_idx(size_t idx, std::index_sequence<I, Is...>) noexcept
        {
            return (idx / ... / Is) % I;
        }

        template <typename Array, size_t N>
        constexpr decltype(auto) deep_get(Array (&array)[N], size_t idx)
        {
            auto const deep_idx = get_deep_idx(idx, Ranks_t<Array[N]>{});

            if constexpr (Ranks_t<Array>::size() == 0)
            {
                return array[deep_idx];
            }
            else
            {
                return deep_get(array[deep_idx], idx);
            }
        }

        template <typename T>
        constexpr decltype(auto) deep_dispatch(T* t, size_t idx)
        {
            if constexpr (std::is_array_v<T>)
            {
                return deep_get(*t, idx);
            }
            else
            {
                return *t;
            }
        }
    }
}
