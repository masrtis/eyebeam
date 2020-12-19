#ifndef INCLUDED_VECTOR4_H_
#define INCLUDED_VECTOR4_H_

#include "constexpr_math.h"

#include <array>
#include <iosfwd>

namespace eyebeam
{

class Vector3
{
public:
    constexpr Vector3() noexcept : Vector3(0.0f, 0.0f, 0.0f)
    {
    }

    constexpr Vector3(float x, float y, float z) noexcept : m_components{x, y, z, 0.0f}
    {
    }

    constexpr auto x() const noexcept
    {
        return m_components[0];
    }

    constexpr auto y() const noexcept
    {
        return m_components[1];
    }

    constexpr auto z() const noexcept
    {
        return m_components[2];
    }

    auto& x() noexcept
    {
        return m_components[0];
    }

    auto& y() noexcept
    {
        return m_components[1];
    }

    auto& z() noexcept
    {
        return m_components[2];
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
        return *this *= (1.0f / rhs);
    }

private:
    std::array<float, 4> m_components;
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

constexpr auto operator==(const Vector3& left, const Vector3& right) noexcept
{
    return areEqual(left.x(), right.x()) && areEqual(left.y(), right.y()) && areEqual(left.z(), right.z());
}

constexpr auto operator!=(const Vector3& left, const Vector3& right) noexcept
{
    return !(left == right);
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

} // namespace eyebeam

#endif // INCLUDED_VECTOR4_H_
