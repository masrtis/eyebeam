#include "vector3.h"

#include <cmath>
#include <ostream>

namespace eyebeam
{

Vector3 operator+(const Vector3& left, const Vector3& right) noexcept
{
    auto result(left);
    result += right;
    return result;
}

Vector3 operator-(const Vector3& left, const Vector3& right) noexcept
{
    auto result(left);
    result -= right;
    return result;
}

Vector3 operator*(const Vector3& left, float right) noexcept
{
    auto result(left);
    result *= right;
    return result;
}

Vector3 operator*(float left, const Vector3& right) noexcept
{
    return right * left;
}

Vector3 operator/(const Vector3& left, float right) noexcept
{
    return left * (1.0F / right);
}

float length(const Vector3& v) noexcept
{
    return std::sqrt(lengthSquared(v));
}

void normalize(Vector3& v) noexcept
{
    v /= length(v);
}

Vector3 norm(Vector3 v) noexcept
{
    normalize(v);
    return v;
}

std::ostream& operator<<(std::ostream& os, const Vector3& out)
{
    return os << "(" << out.x() << ", " << out.y() << ", " << out.z() << ")";
}

} // namespace eyebeam
