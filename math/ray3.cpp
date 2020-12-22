#include "ray3.h"

namespace eyebeam
{

Point3 evaluate(const Ray3& ray, float t) noexcept
{
    return ray.origin() + t * ray.direction();
}

} // namespace eyebeam
