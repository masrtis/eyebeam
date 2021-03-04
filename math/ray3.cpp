#include "ray3.h"

namespace eyebeam
{

Point3 evaluate(const Ray3& ray, float t) noexcept
{
    return ray.origin() + t * ray.direction();
}

bool operator==(const Ray3& lhs, const Ray3& rhs)
{
    return lhs.origin() == rhs.origin() && lhs.direction() == rhs.direction();
}

bool operator!=(const Ray3& lhs, const Ray3& rhs)
{
    return !(lhs == rhs);
}

} // namespace eyebeam
