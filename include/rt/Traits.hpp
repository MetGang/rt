#pragma once

// C++
#include <cstdint>
#include <utility>
#include <type_traits>

namespace rt
{
    template <typename T>
    struct Identity { using type = T; };

    template <auto V>
    struct Constant { static inline constexpr auto value = V; };

    template <size_t V>
    struct Tag { static inline constexpr auto value = V; };

    template <typename To, typename From>
    struct CopyReference : std::remove_reference<To> {};

    template <typename To, typename From>
    struct CopyReference<To, From&> : std::type_identity<std::remove_reference_t<To>&> {};

    template <typename To, typename From>
    struct CopyReference<To, From&&> : std::type_identity<std::remove_reference_t<To>&&> {};

    template <typename To, typename From>
    using CopyReference_t = typename CopyReference<To, From>::type;

    template <typename To, typename From>
    struct ExtentlessCopyReference : CopyReference<std::remove_all_extents_t<To>, From> {};

    template <typename To, typename From>
    using ExtentlessCopyReference_t = typename ExtentlessCopyReference<To, From>::type;

    template <typename, size_t... Is>
    struct Ranks : std::type_identity<std::index_sequence<Is...>> {};

    template <typename Array, std::size_t N, size_t... Is>
    struct Ranks<Array[N], Is...> : Ranks<Array, Is..., N> {};

    template <typename Array>
    using Ranks_t = typename Ranks<Array>::type;

    template <typename>
    struct ArrayFlatSize : std::integral_constant<size_t, 1> {};

    template <typename Array, size_t N>
    struct ArrayFlatSize<Array[N]> : std::integral_constant<size_t, ArrayFlatSize<Array>::value * N> {};

    template <typename Array>
    inline constexpr auto ArrayFlatSize_v = ArrayFlatSize<Array>::value;

    template <typename Array>
    inline constexpr auto ArrayFlatIndices_v = std::make_index_sequence<ArrayFlatSize_v<Array>>{};
}
