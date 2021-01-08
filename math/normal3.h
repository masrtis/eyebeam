#ifndef INCLUDED_NORMAL3_H_
#define INCLUDED_NORMAL3_H_

#include "components.h"
#include "vector3.h"

#include <iosfwd>

namespace eyebeam
{

class Normal3 : public Components
{
public:
    constexpr Normal3() : Components(0.0F, 0.0F, 0.0F, 0.0F)
    {
    }

    constexpr Normal3(float x, float y, float z) : Components(x, y, z, 0.0F)
    {
    }

    explicit Normal3(const Vector3& vector) : Components(norm(vector))
    {
    }

    constexpr explicit operator Vector3() const noexcept
    {
        return Vector3(x(), y(), z());
    }

    auto& operator+=(const Normal3& rhs) noexcept
    {
        x() += rhs.x();
        y() += rhs.y();
        z() += rhs.z();
        return *this;
    }

    auto& operator-=(const Normal3& rhs) noexcept
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

Normal3 operator+(const Normal3& lhs, const Normal3& rhs);
Normal3 operator-(const Normal3& lhs, const Normal3& rhs);
Normal3 operator*(const Normal3& lhs, float rhs);
Normal3 operator*(float lhs, const Normal3& rhs);
Normal3 operator/(const Normal3& lhs, float rhs);

float length(const Normal3& n);
void normalize(Normal3& n);
Normal3 norm(Normal3 n);

std::ostream& operator<<(std::ostream& os, const Normal3& out);

constexpr auto operator-(const Normal3& n)
{
    return Normal3(-n.x(), -n.y(), -n.z());
}

constexpr auto dot(const Normal3& left, const Normal3& right)
{
    return left.x() * right.x() + left.y() * right.y() + left.z() * right.z();
}

constexpr auto dot(const Normal3& left, const Vector3& right)
{
    return left.x() * right.x() + left.y() * right.y() + left.z() * right.z();
}

constexpr auto dot(const Vector3& left, const Normal3& right)
{
    return left.x() * right.x() + left.y() * right.y() + left.z() * right.z();
}

constexpr auto cross(const Vector3& left, const Normal3& right)
{
    return Vector3(
        left.y() * right.z() - left.z() * right.y(),
        left.z() * right.x() - left.x() * right.z(),
        left.x() * right.y() - left.y() * right.x());
}

constexpr auto cross(const Normal3& left, const Vector3& right)
{
    return Vector3(
        left.y() * right.z() - left.z() * right.y(),
        left.z() * right.x() - left.x() * right.z(),
        left.x() * right.y() - left.y() * right.x());
}

constexpr auto lengthSquared(const Normal3& normal)
{
    return dot(normal, normal);
}

} // namespace eyebeam

#endif // INCLUDED_NORMAL3_H_
