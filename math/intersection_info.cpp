#include "intersection_info.h"

#include <limits>

namespace eyebeam
{

IntersectionInfo::IntersectionInfo() : IntersectionInfo(Point3(), Normal3(), std::numeric_limits<float>::max())
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

} // namespace eyebeam
