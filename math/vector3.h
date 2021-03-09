#ifndef INCLUDED_VECTOR4_H_
#define INCLUDED_VECTOR4_H_

// NOLINTNEXTLINE
#include "components.h"
#include "constexpr_math.h"

#include <iosfwd>

namespace eyebeam
{

class Vector3 : public Components
{
public:
    constexpr Vector3() = default;
    explicit constexpr Vector3(float x, float y, float z) noexcept : Components(x, y, z, 0.0F)
    {
    }

    explicit constexpr Vector3(const std::array<float, 3>& values) noexcept : Vector3(values[0], values[1], values[2])
    {
    }

    auto& operator+=(const Vector3& rhs) noexcept
    {
        x() += rhs.x();
        y() += rhs.y();
        z() += rhs.z();
        return *this;
    }

    auto& operator-=(const Vector3& rhs) noexcept
    {
        x() -= rhs.x();
        y() -= rhs.y();
        z() -= rhs.z();
        return *this;
    }

    auto& operator*=(float rhs) noexcept
    {
        x() *= rhs;
        y() *= rhs;
        z() *= rhs;
        return *this;
    }

    auto& operator/=(float rhs) noexcept
    {
        return *this *= (1.0F / rhs);
    }
};

Vector3 operator+(const Vector3& left, const Vector3& right) noexcept;
Vector3 operator-(const Vector3& left, const Vector3& right) noexcept;
Vector3 operator*(const Vector3& left, float right) noexcept;
Vector3 operator*(float left, const Vector3& right) noexcept;
Vector3 operator/(const Vector3& left, float right) noexcept;

float length(const Vector3& v) noexcept;
void normalize(Vector3& v) noexcept;
Vector3 norm(Vector3 v) noexcept;

constexpr auto operator-(const Vector3& operand) noexcept
{
    return Vector3(-operand.x(), -operand.y(), -operand.z());
}

constexpr auto dot(const Vector3& left, const Vector3& right) noexcept
{
    return left.x() * right.x() + left.y() * right.y() + left.z() * right.z();
}

constexpr auto cross(const Vector3& left, const Vector3& right) noexcept
{
    return Vector3(
        left.y() * right.z() - left.z() * right.y(),
        left.z() * right.x() - left.x() * right.z(),
        left.x() * right.y() - left.y() * right.x());
}

constexpr auto lengthSquared(const Vector3& v) noexcept
{
    return dot(v, v);
}

std::ostream& operator<<(std::ostream& os, const Vector3& out);

namespace Axes
{

static constexpr Vector3 X(1.0F, 0.0F, 0.0F);
static constexpr Vector3 Y(0.0F, 1.0F, 0.0F);
static constexpr Vector3 Z(0.0F, 0.0F, 1.0F);

} // namespace Axes

} // namespace eyebeam

#endif // INCLUDED_VECTOR4_H_
