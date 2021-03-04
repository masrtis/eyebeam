#ifndef INCLUDED_ANGLE_H_
#define INCLUDED_ANGLE_H_

namespace eyebeam
{

// [C++20] Replace with std::numbers::pi_v
namespace constants
{

constexpr auto pi = 3.1415926535F;
constexpr auto half_circle = 180.0F;

constexpr auto radians_to_degrees = half_circle / pi;
constexpr auto degrees_to_radians = pi / half_circle;

} // namespace constants

class Radians
{
public:
    explicit constexpr Radians(float theta) noexcept : m_angle(theta)
    {
    }

    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    constexpr operator float() const noexcept
    {
        return m_angle;
    }

private:
    float m_angle;
};

class Degrees
{
public:
    explicit constexpr Degrees(float theta) noexcept : m_angle(theta)
    {
    }

    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    constexpr operator float() const noexcept
    {
        return m_angle;
    }

private:
    float m_angle;
};

constexpr auto toRadians(Degrees theta)
{
    return Radians(theta * constants::degrees_to_radians);
}

constexpr auto toDegrees(Radians theta)
{
    return Degrees(theta * constants::radians_to_degrees);
}

} // namespace eyebeam

#endif // INCLUDED_ANGLE_H_
