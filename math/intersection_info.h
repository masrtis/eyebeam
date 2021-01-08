#ifndef INCLUDED_INTERSECTION_INFO_H_
#define INCLUDED_INTERSECTION_INFO_H_

#include "normal3.h"
#include "point3.h"

namespace eyebeam
{

class IntersectionInfo
{
public:
    IntersectionInfo();

    IntersectionInfo(const Point3& intersection, const Normal3& normal, float time)
        : m_intersectionPoint(intersection)
        , m_normal(norm(normal))
        , m_time(time)
    {
    }

    [[nodiscard]] Normal3 getNormal() const noexcept
    {
        return m_normal;
    }

    [[nodiscard]] Point3 getPoint() const noexcept
    {
        return m_intersectionPoint;
    }

    [[nodiscard]] float getTime() const noexcept
    {
        return m_time;
    }

    void updateWithNewIntersection(const IntersectionInfo& newData) noexcept;

private:
    Point3 m_intersectionPoint;
    Normal3 m_normal;
    float m_time;
};

bool isIntersecting(const IntersectionInfo& intersection) noexcept;

} // namespace eyebeam

#endif // INCLUDED_INTERSECTION_INFO_H_
