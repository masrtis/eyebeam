#include "intersection_info.h"

#include "normal3.h"
#include "point3.h"
#include "quadratic_solver.h"

#include <limits>

namespace eyebeam
{

IntersectionInfo::IntersectionInfo() : IntersectionInfo(Point3(), Normal3(), std::numeric_limits<float>::max())
{
}

IntersectionInfo::IntersectionInfo(const Point3& intersection, const Normal3& normal, float time)
    : m_intersectionPoint(intersection)
    , m_normal(norm(normal))
    , m_time(time)
{
}

void IntersectionInfo::updateWithNewIntersection(const IntersectionInfo& newData) noexcept
{
    if (newData.m_time < m_time)
    {
        m_intersectionPoint = newData.m_intersectionPoint;
        m_normal = newData.m_normal;
        m_time = newData.m_time;
    }
}

bool isIntersecting(const IntersectionInfo& intersection) noexcept
{
    return intersection.getTime() < std::numeric_limits<float>::max();
}

float getEarliestViableIntersection(const QuadraticRoots& t) noexcept
{
    if (t[0] > 0.0F)
    {
        return t[0];
    }

    return t[1];
}

} // namespace eyebeam
