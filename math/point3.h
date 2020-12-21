#ifndef INCLUDED_POINT3_H_
#define INCLUDED_POINT3_H_

// NOLINTNEXTLINE
#include "components.h"
#include "vector3.h"

#include <iosfwd>

namespace eyebeam
{

class Point3 : public Components
{
public:
    constexpr Point3() noexcept
    {
    }

    explicit constexpr Point3(float x, float y, float z) noexcept : Components(x, y, z, 1.0F)
    {
    }

    auto& operator+=(const Vector3& rhs) noexcept
    {
        x() += rhs.x();
        y() += rhs.y();
        z() += rhs.z();
        return *this;
    }

    explicit constexpr operator Vector3() const noexcept
    {
        return Vector3(x(), y(), z());
    }
};

Point3 operator+(const Vector3& lhs, const Point3& rhs);
Point3 operator+(const Point3& lhs, const Vector3& rhs);
Vector3 operator-(const Point3& lhs, const Point3& rhs);

std::ostream& operator<<(std::ostream& os, const Point3& out);

} // namespace eyebeam

#endif // INCLUDED_POINT3_H_
