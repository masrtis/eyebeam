#include "normal3.h"

#include <cmath>
#include <ostream>

namespace eyebeam
{

Normal3 operator+(const Normal3& lhs, const Normal3& rhs)
{
    auto result(lhs);
    result += rhs;
    return result;
}

Normal3 operator-(const Normal3& lhs, const Normal3& rhs)
{
    auto result(lhs);
    result -= rhs;
    return result;
}

Normal3 operator*(const Normal3& lhs, float rhs)
{
    auto result(lhs);
    result *= rhs;
    return result;
}

Normal3 operator*(float lhs, const Normal3& rhs)
{
    auto result(rhs);
    result *= lhs;
    return result;
}

Normal3 operator/(const Normal3& lhs, float rhs)
{
    auto result(lhs);
    result /= rhs;
    return result;
}

float length(const Normal3& normal)
{
    return std::sqrt(lengthSquared(normal));
}

void normalize(Normal3& normal)
{
    normal /= length(normal);
}

Normal3 norm(Normal3 normal)
{
    normalize(normal);
    return normal;
}

std::ostream& operator<<(std::ostream& os, const Normal3& out)
{
    os << "(" << out.x() << ", " << out.y() << ", " << out.z() << ")";
    return os;
}

} // namespace eyebeam
