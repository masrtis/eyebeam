#include "vector3.h"

#include "random_generator.h"

#include "direction_typed_test.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_SUITE_P(InstantiateVector3, DirectionTests, Vector3);

// NOLINTNEXTLINE
TEST(Vector3Tests, CrossReturnsCrossProductBetweenTwoVectors)
{
    // GIVEN:
    constexpr Vector3 v(0.33333333F, 0.33333333F, 0.33333333F);
    constexpr Vector3 w(0.33333333F, -0.33333333F, 0.33333333F);

    // WHEN:
    constexpr auto result(cross(v, w));

    // THEN:
    constexpr Vector3 expected(0.22222222F, 0.0F, -0.22222222F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, CrossProductIsPerpendicularToBothInputVectors)
{
    // GIVEN:
    auto v(RandomGenerator::generateRandomVector3());
    auto w(RandomGenerator::generateRandomVector3());

    normalize(v);
    normalize(w);

    // WHEN:
    auto vCrossW(cross(v, w));
    normalize(vCrossW);

    // THEN:
    EXPECT_TRUE(areEqual(dot(v, vCrossW), 0.0F));
    EXPECT_TRUE(areEqual(dot(w, vCrossW), 0.0F));
}

} // namespace eyebeam
