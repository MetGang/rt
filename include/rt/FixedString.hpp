#pragma once

// C++
#include <array>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

namespace rt
{
    template <typename TChar, size_t vSize>
    class FixedString
    {
    public:

        using Char_t = TChar;

        explicit consteval FixedString(Char_t const* str)
            : m_data {}
        {
            std::copy_n(str, vSize, std::data(m_data));
        }

        template <typename U>
        consteval U as() const
        {
            return { m_data.begin(), m_data.end() };
        }

        consteval std::basic_string<Char_t> as_string() const
        {
            return { m_data.begin(), m_data.end() };
        }

        consteval std::basic_string_view<Char_t> as_string_view() const
        {
            return { m_data.begin(), m_data.end() };
        }

        consteval std::array<Char_t, vSize> as_array() const
        {
            return { m_data.begin(), m_data.end() };
        }

        consteval std::vector<Char_t> as_vector() const
        {
            return { m_data.begin(), m_data.end() };
        }

        consteval auto operator<=>(FixedString const&) const noexcept = default;

    private:

        std::array<Char_t, vSize> m_data;
    };

    template <typename TChar, size_t vSize>
    FixedString(TChar const (&str)[vSize]) -> FixedString<TChar, vSize - 1>;
}
