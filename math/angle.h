#ifndef INCLUDED_ANGLE_H_
#define INCLUDED_ANGLE_H_

namespace eyebeam
{

// [C++20] Replace with std::numbers::pi_v
namespace constants
{

constexpr auto pi = 3.1415926535F;

}

class Radians
{
public:
    explicit constexpr Radians(float theta) noexcept : m_angle(theta)
    {
    }

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

    constexpr operator float() const noexcept
    {
        return m_angle;
    }

private:
    float m_angle;
};

constexpr auto toRadians(Degrees theta)
{
    return theta * (constants::pi / 180.0F);
}

constexpr auto toDegrees(Radians theta)
{
    return theta * (180.0F / constants::pi);
}

} // namespace eyebeam

#endif // INCLUDED_ANGLE_H_
