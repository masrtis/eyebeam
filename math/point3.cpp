#include "point3.h"

#include <ostream>

namespace eyebeam
{

Point3 operator+(const Point3& lhs, const Vector3& rhs)
{
    auto result(lhs);
    result += rhs;
    return result;
}

Point3 operator+(const Vector3& lhs, const Point3& rhs)
{
    auto result(rhs);
    result += lhs;
    return result;
}

Vector3 operator-(const Point3& lhs, const Point3& rhs)
{
    Vector3 result(lhs);
    result -= Vector3(rhs);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Point3& out)
{
    return os << "(" << out.x() << ", " << out.y() << ", " << out.z() << ")";
}

} // namespace eyebeam
