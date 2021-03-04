#ifndef INCLUDED_RAY3_H_
#define INCLUDED_RAY3_H_

#include "point3.h"
#include "vector3.h"

#include <utility>

namespace eyebeam
{

class Ray3
{
public:
    explicit Ray3(const Point3& origin, const Vector3& direction) noexcept
        : m_origin(origin)
        , m_direction(norm(direction))
    {
    }

    [[nodiscard]] auto origin() const noexcept
    {
        return m_origin;
    }

    [[nodiscard]] auto direction() const noexcept
    {
        return m_direction;
    }

private:
    Point3 m_origin;
    Vector3 m_direction;
};

Point3 evaluate(const Ray3& ray, float t) noexcept;

bool operator==(const Ray3& lhs, const Ray3& rhs);
bool operator!=(const Ray3& lhs, const Ray3& rhs);

} // namespace eyebeam

#endif // INCLUDED_RAY3_H_
