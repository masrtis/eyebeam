#include "ray3.h"

#include <gtest/gtest.h>

namespace eyebeam
{

namespace
{

// NOLINTNEXTLINE
TEST(Ray3Tests, evaluateReturnsOriginAtTEqualsZero)
{
    // GIVEN:
    constexpr Point3 origin(2.5F, 1.25F, -0.333F);
    constexpr Vector3 direction(1.0F, 1.0F, 1.0F);
    const Ray3 ray(origin, direction);

    // WHEN:
    const auto result(evaluate(ray, 0.0F));

    // THEN:
    EXPECT_EQ(result, origin);
}

// NOLINTNEXTLINE
TEST(Ray3Tests, getDirectionReturnsLengthOneWhenConstructedWithNonNormalVector)
{
    // GIVEN:
    constexpr Point3 origin;
    constexpr Vector3 direction(1.0F, 1.0F, 1.0F);
    const Ray3 ray(origin, direction);

    // WHEN:
    const auto result(ray.direction());

    // THEN:
    const auto resultLength(length(result));
    EXPECT_TRUE(areEqual(resultLength, 1.0F));
}

} // namespace

} // namespace eyebeam
