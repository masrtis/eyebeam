#include "point3.h"

#include <gtest/gtest.h>

namespace eyebeam
{

namespace
{

// NOLINTNEXTLINE
TEST(Point3Tests, OperatorPlusEqualAddsConstantVector3ToLeftSide)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    Point3 left(0.0F, -1.0F, 2.5F);
    constexpr Vector3 right(-1.0F, 1.0F, -2.5F);

    // WHEN:
    left += right;

    // THEN:
    constexpr Point3 expected(-1.0F, 0.0F, 0.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TEST(Point3Tests, OperatorPlusAddsPointAndVector)
{
    // GIVEN:
    constexpr Point3 left(0.5F, 0.75F, -0.25F);
    constexpr Vector3 right(-0.5F, 0.0F, -0.25F);

    // WHEN:
    const auto result(left + right);

    // THEN:
    constexpr Point3 expected(0.0F, 0.75F, -0.5F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Point3Tests, OperatorPlusAddsVectorAndPoint)
{
    // GIVEN:
    constexpr Vector3 left(0.5F, 0.75F, -0.25F);
    constexpr Point3 right(-0.5F, 0.0F, 1.25F);

    // WHEN:
    const auto result(left + right);

    // THEN:
    constexpr Point3 expected(0.0F, 0.75F, 1.0F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Point3, OperatorMinusSubtractsTwoConstantPoints)
{
    // GIVEN:
    constexpr Point3 left(4.0F, 0.25F, 0.0F);
    constexpr Point3 right(2.0F, -0.75F, 0.3F);

    // WHEN:
    const auto result(left - right);

    // THEN:
    constexpr Vector3 expected(2.0F, 1.0F, -0.3F);
    EXPECT_EQ(expected, result);
}

} // namespace

} // namespace eyebeam
