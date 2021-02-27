#include "quadratic_solver.h"

#include "constexpr_math.h"

#include <gtest/gtest.h>

#include <array>

namespace eyebeam
{

class QuadraticSolverTestsFixture : public ::testing::Test
{
protected:
    QuadraticRoots m_roots;
};

// NOLINTNEXTLINE
TEST_F(QuadraticSolverTestsFixture, ThrowsDomainErrorWhenAIsZero)
{
    // GIVEN:
    const float a = 0.0F;
    const float b = 0.0F;
    const float c = 0.0F;

    // WHEN/THEN:
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto)
    EXPECT_THROW([[maybe_unused]] bool result = solveQuadratic(a, b, c, m_roots);, std::domain_error);
}

// NOLINTNEXTLINE
TEST_F(QuadraticSolverTestsFixture, ReturnsEquivalentRootsWhenFormulaHasOneRoot)
{
    // GIVEN:
    const float a = 1.0F;
    const float b = 0.0F;
    const float c = 0.0F;

    // WHEN:
    const auto result = solveQuadratic(a, b, c, m_roots);

    // THEN:
    ASSERT_TRUE(result);
    EXPECT_TRUE(areEqual(m_roots[0], m_roots[1]));
    EXPECT_TRUE(areEqual(m_roots[0], 0.0F));
}

// NOLINTNEXTLINE
TEST_F(QuadraticSolverTestsFixture, ReturnsFalseWhenFormulaHasNoRealRoots)
{
    // GIVEN:
    const float a = 1.0F;
    const float b = 0.0F;
    const float c = 1.0F;

    // WHEN:
    const auto result = solveQuadratic(a, b, c, m_roots);

    // THEN:
    EXPECT_FALSE(result);
}

// NOLINTNEXTLINE
TEST_F(QuadraticSolverTestsFixture, ReturnsCorrectRootsWhenLinearCoefficientIsNegative)
{
    // GIVEN:
    const float a = 1.0F;
    const float b = -1.0F;
    const float c = -2.0F;

    // WHEN:
    const auto result = solveQuadratic(a, b, c, m_roots);

    // THEN:
    const QuadraticRoots expected{-1.0F, 2.0F};
    ASSERT_TRUE(result);
    EXPECT_TRUE(areEqual(expected[0], m_roots[0]));
    EXPECT_TRUE(areEqual(expected[1], m_roots[1]));
}

// NOLINTNEXTLINE
TEST_F(QuadraticSolverTestsFixture, TestCatastrophicCancellation)
{
    // GIVEN:
    const float a = 1.0F;
    const float b = 444.0F;
    const float c = 1.0F;

    // WHEN:
    const auto result = solveQuadratic(a, b, c, m_roots);

    // THEN:
    const QuadraticRoots expected{-443.99774773632276650F, -0.00225226367723350F};
    ASSERT_TRUE(result);
    EXPECT_TRUE(areEqual(m_roots[0], expected[0]));
    EXPECT_TRUE(areEqual(m_roots[1], expected[1]));
}

} // namespace eyebeam
