#include "vector3.h"

#include "random_generator.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorPlusEqualAddsConstantRightSideToLeftSide)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    Vector3 left(1.0F, -1.0F, 2.5F);
    constexpr Vector3 right(-1.0F, 1.0F, -2.5F);

    // WHEN:
    left += right;

    // THEN:
    constexpr Vector3 expected;
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorPlusAddsTwoConstantVectors)
{
    // GIVEN:
    constexpr Vector3 left(0.5F, 0.75F, -0.25F);
    constexpr Vector3 right(-0.5F, 0.75F, -0.25F);

    // WHEN:
    const auto result(left + right);

    // THEN:
    constexpr Vector3 expected(0.0F, 1.5F, -0.5F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorMinusEqualSubtractsConstantRightSideFromLeftSide)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    Vector3 left(-3.0F, 1.0F, 0.0F);
    constexpr Vector3 right(0.0F, 2.0F, -1.0F);

    // WHEN:
    left -= right;

    // THEN:
    constexpr Vector3 expected(-3.0F, -1.0F, 1.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorMinusSubtractsTwoConstantVectors)
{
    // GIVEN:
    constexpr Vector3 left(1.0F, -0.25F, 0.0F);
    constexpr Vector3 right(2.0F, -0.75F, 0.3F);

    // WHEN:
    const auto result(left - right);

    // THEN:
    constexpr Vector3 expected(-1.0F, 0.5F, -0.3F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorMultiplyEqualScalesVectorByConstant)
{
    // GIVEN:
    constexpr float scale = 0.5F;
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    Vector3 left(1.0F, 2.0F, -4.0F);

    // WHEN:
    left *= scale;

    // THEN:
    constexpr Vector3 expected(0.5F, 1.0F, -2.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorMultiplyScalesConstantVectorByConstantOnRightSide)
{
    // GIVEN:
    constexpr float scale = 2.0F;
    constexpr Vector3 left(-0.25F, -0.66666667F, 1.0F);

    // WHEN:
    const auto result(left * scale);

    // THEN:
    constexpr Vector3 expected(-0.5F, -1.33333334F, 2.0F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorMultiplyScalesConstantVectorByConstantOnLeftSide)
{
    // GIVEN:
    constexpr float scale = -1.5F;
    constexpr Vector3 right(0.1F, -1.0F, 0.5F);

    // WHEN:
    const auto result(scale * right);

    // THEN:
    constexpr Vector3 expected(-0.15F, 1.5F, -0.75F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorDivideEqualScalesVectorByConstant)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    constexpr float scale = 4.0F;
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    Vector3 left(4.0F, -8.0F, 16.0F);

    // WHEN:
    left /= scale;

    // THEN:
    constexpr Vector3 expected(1.0F, -2.0F, 4.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, OperatorDivideScalesConstantVectorByConstant)
{
    // GIVEN:
    constexpr float scale = 2.0F;
    constexpr Vector3 left(1.0F, 4.0F, -2.0F);

    // WHEN:
    const auto result(left / scale);

    // THEN:
    constexpr Vector3 expected(0.5F, 2.0F, -1.0F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, NegationOperatorNegatesConstantVector)
{
    // GIVEN:
    constexpr Vector3 v(2.5F, -1.5F, 0.75F);

    // WHEN:
    constexpr Vector3 result(-v);

    // THEN:
    constexpr Vector3 expected(-2.5F, 1.5F, -0.75F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TEST(Vector3Tests, DotReturnsDotProductBetweenTwoVectors)
{
    // GIVEN:
    constexpr Vector3 v(1.0F, -1.0F, 0.0F);
    constexpr Vector3 w(-2.0F, 1.0F, 1.0F);

    // WHEN:
    constexpr auto result = dot(v, w);

    // THEN:
    constexpr auto expected = -3.0F;
    EXPECT_EQ(expected, result);
}

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

// NOLINTNEXTLINE
TEST(Vector3Tests, LengthSquaredReturnsSquaredLength)
{
    // GIVEN:
    constexpr Vector3 v(0.5F, 0.33333333F, 1.0F);

    // WHEN:
    constexpr auto result = lengthSquared(v);

    // THEN:
    constexpr auto expected = 1.36111111F;
    EXPECT_TRUE(areEqual(expected, result));
}

// NOLINTNEXTLINE
TEST(Vector3Tests, LengthReturnsVectorLength)
{
    // GIVEN:
    constexpr Vector3 v(0.5F, -0.33333333F, 1.0F);

    // WHEN:
    const auto result = length(v);

    // THEN:
    constexpr auto expected = 1.16666667F;
    EXPECT_TRUE(areEqual(expected, result));
}

// NOLINTNEXTLINE
TEST(Vector3Tests, NormalizeReducesLengthToOne)
{
    // GIVEN:
    auto v(RandomGenerator::generateRandomVector3());

    // WHEN:
    normalize(v);

    // THEN:
    EXPECT_TRUE(areEqual(1.0F, length(v)));
}

// NOLINTNEXTLINE
TEST(Vector3Tests, NormIsParallelToInputVector)
{
    // GIVEN:
    const auto v(RandomGenerator::generateRandomVector3());

    // WHEN:
    const auto vNorm(norm(v));
    const auto vDotvNorm(dot(v, vNorm));
    const auto cosTheta(vDotvNorm / length(v));

    // THEN:
    EXPECT_TRUE(areEqual(1.0F, cosTheta));
}

} // namespace eyebeam
