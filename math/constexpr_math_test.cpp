#include "constexpr_math.h"

#include <stdexcept>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace eyebeam
{

class UnaryFunctionInputResult
{
public:
    constexpr UnaryFunctionInputResult(float input, float result) noexcept : m_input(input), m_result(result)
    {
    }

    constexpr auto input() const noexcept
    {
        return m_input;
    }

    constexpr auto result() const noexcept
    {
        return m_result;
    }

private:
    float m_input;
    float m_result;
};

class AbsoluteValueTests : public testing::TestWithParam<UnaryFunctionInputResult>
{
};

// NOLINTNEXTLINE
TEST_P(AbsoluteValueTests, AbsoluteValueBoundaryTest)
{
    // GIVEN:
    const auto parameter(GetParam());

    // WHEN:
    const auto result = abs(parameter.input());

    // THEN:
    EXPECT_EQ(result, parameter.result());
}

// NOLINTNEXTLINE
INSTANTIATE_TEST_SUITE_P(
    ConstexprMathTests,
    AbsoluteValueTests,
    testing::Values(
        UnaryFunctionInputResult(-1.0F, 1.0F),
        UnaryFunctionInputResult(0.0F, 0.0F),
        // NOLINTNEXTLINE(readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
        UnaryFunctionInputResult(3.0F, 3.0F)));

// NOLINTNEXTLINE
TEST(ConstexprMathTests, SqrtThrowsOnNegativeInput)
{
    // GIVEN:
    constexpr auto x = -1.0F;

    // WHEN/THEN:
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto, hicpp-avoid-goto)
    EXPECT_THROW(sqrt(x), std::domain_error);
}

// NOLINTNEXTLINE
TEST(ConstexprMathTests, SqrtOfZeroEqualsZero)
{
    // GIVEN:
    constexpr auto x = 0.0F;

    // WHEN:
    constexpr auto result = sqrt(x);

    // THEN:
    EXPECT_EQ(result, 0.0F);
}

// NOLINTNEXTLINE
TEST(ConstexprMathTests, SqrtOfNineEqualsThree)
{
    // GIVEN:
    constexpr auto x = 9.0F;

    // WHEN:
    constexpr auto result = sqrt(x);

    // THEN:
    EXPECT_EQ(result, 3.0F);
}

} // namespace eyebeam
