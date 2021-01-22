#include "intersection_info.h"

#include "normal3.h"
#include "point3.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
TEST(IntersectionInfoTests, updateWithNewIntersectionDoesNotUpdateIfNewTimeIsLargerThanOldTime)
{
    // GIVEN:
    constexpr Point3 expectedPoint;
    constexpr Normal3 expectedNormal(0.0F, 1.0F, 0.0F);
    constexpr float expectedTime(1.0F);
    IntersectionInfo old(expectedPoint, expectedNormal, 1.0F);
    const IntersectionInfo latest(Point3(1.0F, 0.0F, 1.0F), Normal3(1.0F, 0.0F, 0.0F), 2.0F);

    // WHEN:
    old.updateWithNewIntersection(latest);

    // THEN:
    EXPECT_EQ(old.getPoint(), expectedPoint);
    EXPECT_EQ(old.getNormal(), expectedNormal);
    EXPECT_EQ(old.getTime(), expectedTime);
}

// NOLINTNEXTLINE
TEST(IntersectionInfoTests, updateWithNewIntersectionUpdatesWhenNewTimeIsSmallerThanOldTime)
{
    // GIVEN:
    constexpr Point3 expectedPoint(1.0F, 0.0F, 1.0F);
    constexpr Normal3 expectedNormal(0.0F, 1.0F, 0.0F);
    constexpr float expectedTime(1.0F);
    IntersectionInfo old(Point3(), Normal3(0.0F, 1.0F, 0.0F), 2.0F);
    const IntersectionInfo latest(expectedPoint, expectedNormal, expectedTime);

    // WHEN:
    old.updateWithNewIntersection(latest);

    // THEN:
    EXPECT_EQ(old.getPoint(), expectedPoint);
    EXPECT_EQ(old.getNormal(), expectedNormal);
    EXPECT_EQ(old.getTime(), expectedTime);
}

// NOLINTNEXTLINE
TEST(IntersectionInfoTests, defaultIntersectionInfoDoesNotIntersect)
{
    // GIVEN:
    const IntersectionInfo defaulted;

    // WHEN:
    const auto result = isIntersecting(defaulted);

    // THEN:
    EXPECT_FALSE(result);
}

} // namespace eyebeam
