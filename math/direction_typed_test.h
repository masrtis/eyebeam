#include "random_generator.h"

#include <gtest/gtest.h>

namespace eyebeam
{

template <typename T> class DirectionTests : public testing::Test
{
};

// NOLINTNEXTLINE
TYPED_TEST_SUITE_P(DirectionTests);

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorPlusEqualAddsConstantRightSideToLeftSide)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    TypeParam left(1.0F, -1.0F, 2.5F);
    constexpr TypeParam right(-1.0F, 1.0F, -2.5F);

    // WHEN:
    left += right;

    // THEN:
    constexpr TypeParam expected;
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorPlusAddsTwoConstantVectors)
{
    // GIVEN:
    constexpr TypeParam left(0.5F, 0.75F, -0.25F);
    constexpr TypeParam right(-0.5F, 0.75F, -0.25F);

    // WHEN:
    const auto result(left + right);

    // THEN:
    constexpr TypeParam expected(0.0F, 1.5F, -0.5F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorMinusEqualSubtractsConstantRightSideFromLeftSide)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    TypeParam left(-3.0F, 1.0F, 0.0F);
    constexpr TypeParam right(0.0F, 2.0F, -1.0F);

    // WHEN:
    left -= right;

    // THEN:
    constexpr TypeParam expected(-3.0F, -1.0F, 1.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorMinusSubtractsTwoConstantVectors)
{
    // GIVEN:
    constexpr TypeParam left(1.0F, -0.25F, 0.0F);
    constexpr TypeParam right(2.0F, -0.75F, 0.3F);

    // WHEN:
    const auto result(left - right);

    // THEN:
    constexpr TypeParam expected(-1.0F, 0.5F, -0.3F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorMultiplyEqualScalesVectorByConstant)
{
    // GIVEN:
    constexpr float scale = 0.5F;
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    TypeParam left(1.0F, 2.0F, -4.0F);

    // WHEN:
    left *= scale;

    // THEN:
    constexpr TypeParam expected(0.5F, 1.0F, -2.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorMultiplyScalesConstantVectorByConstantOnRightSide)
{
    // GIVEN:
    constexpr float scale = 2.0F;
    constexpr TypeParam left(-0.25F, -0.66666667F, 1.0F);

    // WHEN:
    const auto result(left * scale);

    // THEN:
    constexpr TypeParam expected(-0.5F, -1.33333334F, 2.0F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorMultiplyScalesConstantVectorByConstantOnLeftSide)
{
    // GIVEN:
    constexpr float scale = -1.5F;
    constexpr TypeParam right(0.1F, -1.0F, 0.5F);

    // WHEN:
    const auto result(scale * right);

    // THEN:
    constexpr TypeParam expected(-0.15F, 1.5F, -0.75F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorDivideEqualScalesVectorByConstant)
{
    // GIVEN:
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    constexpr float scale = 4.0F;
    // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
    TypeParam left(4.0F, -8.0F, 16.0F);

    // WHEN:
    left /= scale;

    // THEN:
    constexpr TypeParam expected(1.0F, -2.0F, 4.0F);
    EXPECT_EQ(expected, left);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, OperatorDivideScalesConstantVectorByConstant)
{
    // GIVEN:
    constexpr float scale = 2.0F;
    constexpr TypeParam left(1.0F, 4.0F, -2.0F);

    // WHEN:
    const auto result(left / scale);

    // THEN:
    constexpr TypeParam expected(0.5F, 2.0F, -1.0F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, NegationOperatorNegatesConstantVector)
{
    // GIVEN:
    constexpr TypeParam v(2.5F, -1.5F, 0.75F);

    // WHEN:
    constexpr TypeParam result(-v);

    // THEN:
    constexpr TypeParam expected(-2.5F, 1.5F, -0.75F);
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, DotReturnsDotProductBetweenTwoVectors)
{
    // GIVEN:
    constexpr TypeParam v(1.0F, -1.0F, 0.0F);
    constexpr TypeParam w(-2.0F, 1.0F, 1.0F);

    // WHEN:
    constexpr auto result = dot(v, w);

    // THEN:
    constexpr auto expected = -3.0F;
    EXPECT_EQ(expected, result);
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, LengthSquaredReturnsSquaredLength)
{
    // GIVEN:
    constexpr TypeParam v(0.5F, 0.33333333F, 1.0F);

    // WHEN:
    constexpr auto result = lengthSquared(v);

    // THEN:
    constexpr auto expected = 1.36111111F;
    EXPECT_TRUE(areEqual(expected, result));
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, LengthReturnsVectorLength)
{
    // GIVEN:
    constexpr TypeParam v(0.5F, -0.33333333F, 1.0F);

    // WHEN:
    const auto result = length(v);

    // THEN:
    constexpr auto expected = 1.16666667F;
    EXPECT_TRUE(areEqual(expected, result));
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, NormalizeReducesLengthToOne)
{
    // GIVEN:
    auto v(TypedRandomGenerator<TypeParam>::generate());

    // WHEN:
    normalize(v);

    // THEN:
    EXPECT_TRUE(areEqual(1.0F, length(v)));
}

// NOLINTNEXTLINE
TYPED_TEST_P(DirectionTests, NormIsParallelToInputVector)
{
    // GIVEN:
    const auto v(TypedRandomGenerator<TypeParam>::generate());

    // WHEN:
    const auto vNorm(norm(v));
    const auto vDotvNorm(dot(v, vNorm));
    const auto cosTheta(vDotvNorm / length(v));

    // THEN:
    EXPECT_TRUE(areEqual(1.0F, cosTheta));
}

// NOLINTNEXTLINE
REGISTER_TYPED_TEST_SUITE_P(
    DirectionTests,
    OperatorPlusEqualAddsConstantRightSideToLeftSide,
    OperatorPlusAddsTwoConstantVectors,
    OperatorMinusEqualSubtractsConstantRightSideFromLeftSide,
    OperatorMinusSubtractsTwoConstantVectors,
    OperatorMultiplyEqualScalesVectorByConstant,
    OperatorMultiplyScalesConstantVectorByConstantOnRightSide,
    OperatorMultiplyScalesConstantVectorByConstantOnLeftSide,
    OperatorDivideEqualScalesVectorByConstant,
    OperatorDivideScalesConstantVectorByConstant,
    NegationOperatorNegatesConstantVector,
    DotReturnsDotProductBetweenTwoVectors,
    LengthSquaredReturnsSquaredLength,
    LengthReturnsVectorLength,
    NormalizeReducesLengthToOne,
    NormIsParallelToInputVector);

} // namespace eyebeam
