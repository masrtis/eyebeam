#include "matrix4.h"

#include "point3.h"

#include <gtest/gtest.h>

namespace eyebeam
{

class Matrix4TestFixture : public testing::Test
{
public:
    Matrix4TestFixture()
        : m_translation(AlignedMatrixStorage{
              1.0F,
              0.0F,
              0.0F,
              2.0F,
              0.0F,
              1.0F,
              0.0F,
              -3.0F,
              0.0F,
              0.0F,
              1.0F,
              2.0F,
              0.0F,
              0.0F,
              0.0F,
              1.0F})
        , m_rotation(AlignedMatrixStorage{
              1.0F,
              0.0F,
              0.0F,
              0.0F,
              0.0F,
              0.0F,
              -1.0F,
              0.0F,
              0.0F,
              1.0F,
              0.0F,
              0.0F,
              0.0F,
              0.0F,
              0.0F,
              1.0F})
    {
    }

protected:
    Matrix4 m_translation;
    Matrix4 m_rotation;
};

// NOLINTNEXTLINE
TEST(Matrix4Tests, Matrix4DefaultConstructorIsIdentityMatrix)
{
    // GIVEN:
    constexpr Matrix4 identity;

    // WHEN:
    const auto result = isIdentity(identity);

    // THEN:
    EXPECT_TRUE(result);
}

// NOLINTNEXTLINE
TEST(Matrix4Tests, Matrix4TransposeResultsInTransposedMatrix)
{
    constexpr Matrix4 test(AlignedMatrixStorage{
        1.0F,
        2.0F,
        3.0F,
        4.0F,
        5.0F,
        6.0F,
        7.0F,
        8.0F,
        9.0F,
        10.0F,
        11.0F,
        12.0F,
        13.0F,
        14.0F,
        15.0F,
        16.0F});
    constexpr Matrix4 expected(AlignedMatrixStorage{
        1.0F,
        5.0F,
        9.0F,
        13.0F,
        2.0F,
        6.0F,
        10.0F,
        14.0F,
        3.0F,
        7.0F,
        11.0F,
        15.0F,
        4.0F,
        8.0F,
        12.0F,
        16.0F});

    // WHEN:
    constexpr auto result(test.transpose());

    // THEN:
    EXPECT_EQ(result, expected);
}

// NOLINTNEXTLINE
TEST(Matrix4Tests, InvertingTheZeroMatrixThrowsRuntimeError)
{
    // GIVEN:
    constexpr Matrix4 zero(AlignedMatrixStorage{
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F});

    // WHEN/THEN:
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto)
    EXPECT_THROW([[maybe_unused]] const auto inverse = zero.inverse(), std::runtime_error);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4TranslationMatrixIsNotTheIdentityMatrix)
{
    // GIVEN:

    // WHEN:
    const auto result = isIdentity(m_translation);

    // THEN:
    EXPECT_FALSE(result);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4MultiplyCombinesTranslationAndRotationMatrices)
{
    // GIVEN:
    constexpr Matrix4 expected(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        2.0F,
        0.0F,
        0.0F,
        -1.0F,
        -3.0F,
        0.0F,
        1.0F,
        0.0F,
        2.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    // WHEN:
    const auto result(m_translation.multiply(m_rotation));

    // THEN:
    EXPECT_EQ(result, expected);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4MultiplyTranslatesPoints)
{
    // GIVEN:
    constexpr Point3 origin;
    constexpr Point3 expected(2.0F, -3.0F, 2.0F);

    // WHEN:
    const auto result(m_translation.multiply(origin));

    // THEN:
    EXPECT_EQ(result, expected);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4MultiplyTranslationDoesNotModifyVectors)
{
    // GIVEN:
    constexpr Vector3 origin;

    // WHEN:
    const auto result(m_translation.multiply(origin));

    // THEN:
    EXPECT_EQ(result, origin);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4MultiplyRotatesPoints)
{
    // GIVEN:
    constexpr Point3 point(-1.0F, 1.0F, 3.0F);
    constexpr Point3 expected(-1.0F, -3.0F, 1.0F);

    // WHEN:
    const auto result(m_rotation.multiply(point));

    // THEN:
    EXPECT_EQ(result, expected);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4InverseGeneratesTransposeForRotationMatrix)
{
    // GIVEN:
    const auto expected(m_rotation.transpose());

    // WHEN:
    const auto result(m_rotation.inverse());

    // THEN:
    EXPECT_EQ(result, expected);
}

// NOLINTNEXTLINE
TEST_F(Matrix4TestFixture, Matrix4InverseGeneratesNegatedTranslationForTranslationMatrix)
{
    // GIVEN:
    constexpr Matrix4 expected(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        -2.0F,
        0.0F,
        1.0F,
        0.0F,
        3.0F,
        0.0F,
        0.0F,
        1.0F,
        -2.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    // WHEN
    const auto result(m_translation.inverse());

    // THEN
    EXPECT_EQ(result, expected);
}

} // namespace eyebeam
