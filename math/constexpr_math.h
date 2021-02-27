#ifndef INCLUDED_CONSTEXPR_MATH_H_
#define INCLUDED_CONSTEXPR_MATH_H_

#include <algorithm>
#include <limits>
#include <stdexcept>

namespace eyebeam
{

constexpr float abs(float x) noexcept
{
    if (x < 0.0F)
    {
        return -x;
    }

    return x;
}

constexpr float sqrt(float x)
{
    if (x < 0.0F)
    {
        throw std::domain_error("Negative value passed to sqrt()");
    }

    if (x == 0.0F)
    {
        return 0.0F;
    }

    auto guess = x;
    auto nextGuess = 0.5F * (guess + x / guess);

    while (abs(guess - nextGuess) > std::numeric_limits<float>::epsilon())
    {
        guess = nextGuess;
        nextGuess = 0.5F * (guess + x / guess);
    }

    return guess;
}

// NOLINTNEXTLINE(bugprone-exception-escape)
constexpr bool areEqual(float left, float right) noexcept
{
    static_assert(std::numeric_limits<float>::epsilon() > 0.0F);

    constexpr auto epsilon = sqrt(std::numeric_limits<float>::epsilon());
    return abs(left - right) <= epsilon * std::max({1.0F, left, right});
}

template <size_t Size>
bool areEqual(const std::array<float, Size>& left, const std::array<float, Size>& right)
{
    return std::equal(begin(left), end(left), begin(right), end(right), [](float x, float y) {
        return areEqual(x, y);
    });
}

} // namespace eyebeam

#endif // INCLUDED_CONSTEXPR_MATH_H_
