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

    float guess = x;
    float nextGuess = 0.5F * (guess + x / guess);

    while (abs(guess - nextGuess) > std::numeric_limits<float>::epsilon())
    {
        guess = nextGuess;
        nextGuess = 0.5F * (guess + x / guess);
    }

    return guess;
}

constexpr bool areEqual(float left, float right) noexcept
{
    constexpr float epsilon = sqrt(std::numeric_limits<float>::epsilon());
    return abs(left - right) <= epsilon * std::max({1.0F, left, right});
}

} // namespace eyebeam

#endif // INCLUDED_CONSTEXPR_MATH_H_
