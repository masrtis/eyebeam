#include "transform.h"

#include "random_generator.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
TEST(TransformTests, DefaultCtorResultsInIdentityTransform)
{
    // GIVEN:
    constexpr Transform t;

    // WHEN:
    const auto result = t.isIdentity();

    // THEN:
    EXPECT_TRUE(result);
}

// NOLINTNEXTLINE
TEST(TransformTests, TransposeSwapsRowsWithColumnsForMandMInverse)
{
    // GIVEN:
    // clang-format off
    const Matrix4 m(AlignedMatrixStorage{
        1.0F, 2.0F, 3.0F, 4.0F,
        5.0F, -6.0F, 7.0F, 8.0F,
        9.0F, 10.0F, 11.0F, -12.0F,
        13.0F, 14.0F, 15.0F, 16.0F
    });

    const Matrix4 transposed(AlignedMatrixStorage{
        1.0F, 5.0F, 9.0F, 13.0F,
        2.0F, -6.0F, 10.0F, 14.0F,
        3.0F, 7.0F, 11.0F, 15.0F,
        4.0F, 8.0F, -12.0F, 16.0F
    });
    // clang-format on

    const Transform t(m, m.inverse());
    const Transform tTransposed(transposed, transposed.inverse());

    // WHEN:
    const auto result(t.transpose());

    // THEN:
    EXPECT_EQ(result, tTransposed);
}

// NOLINTNEXTLINE
TEST(TransformTests, TranslateInverseIsEquivalentToTranslateInOppositeDirection)
{
    // GIVEN:
    const Vector3 delta(1.0F, 2.0F, -3.0F);
    const auto t(Transform::translate(delta));

    // WHEN:
    const auto result(t.inverse());

    // THEN:
    const auto tInverse(Transform::translate(-delta));
    EXPECT_EQ(result, tInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, ScaleInverseIsEquivalentToReciprocalScale)
{
    // GIVEN:
    const auto s(Transform::scale(2.0F, 0.5F, 3.0F));

    // WHEN:
    const auto result(s.inverse());

    // THEN:
    const auto sInverse(Transform::scale(0.5F, 2.0F, 0.33333333F));
    EXPECT_EQ(result, sInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, RotateXInverseIsEquivalentToRotationWithNegativeRotationAngle)
{
    // GIVEN:
    const Radians angle(constants::pi * 0.5F);
    const auto rX(Transform::rotateX(angle));

    // WHEN:
    const auto result(rX.inverse());

    // THEN:
    const Radians oppositeAngle(-angle);
    const auto rXInverse(Transform::rotateX(oppositeAngle));
    EXPECT_EQ(result, rXInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, RotateYInverseIsEquivalentToRotationWithNegativeRotationAngle)
{
    // GIVEN:
    const Radians angle(constants::pi * 0.5F);
    const auto rY(Transform::rotateY(angle));

    // WHEN:
    const auto result(rY.inverse());

    // THEN:
    const Radians oppositeAngle(-angle);
    const auto rYInverse(Transform::rotateY(oppositeAngle));
    EXPECT_EQ(result, rYInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, RotateZInverseIsEquivalentToRotationWithNegativeRotationAngle)
{
    // GIVEN:
    const Radians angle(constants::pi * 0.5F);
    const auto rZ(Transform::rotateZ(angle));

    // WHEN:
    const auto result(rZ.inverse());

    // THEN:
    const Radians oppositeAngle(-angle);
    const auto rZInverse(Transform::rotateZ(oppositeAngle));
    EXPECT_EQ(result, rZInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, RotationAroundArbitraryAxisInverseIsEquivalentToRotationWithNegativeRotationAngle)
{
    // GIVEN:
    const auto randomAxis(RandomGenerator::generateRandomVector3());
    const Radians angle(1.5F * constants::pi);
    const auto rAxisAngle(Transform::rotateAxisAngle(randomAxis, angle));

    // WHEN:
    const auto result(rAxisAngle.inverse());

    // THEN:
    const Radians oppositeAngle(-angle);
    const auto rAxisAngleInverse(Transform::rotateAxisAngle(randomAxis, oppositeAngle));
    EXPECT_EQ(result, rAxisAngleInverse);
}

// NOLINTNEXTLINE
TEST(TransformTests, LookAtConstructsCorrectInvertibleCameraSpaceMatrix)
{
    // GIVEN:
    const auto randomCameraPosition(RandomGenerator::generateRandomPoint3());
    constexpr auto upAxis(Axes::Y);
    const auto lookAt(randomCameraPosition + 5.0F * Axes::Z);
    const auto worldToCamera(Transform::lookAt(randomCameraPosition, lookAt, upAxis));

    // clang-format off
    const Matrix4 worldToCameraInverse(AlignedMatrixStorage{
        1.0F, 0.0F, 0.0F, -randomCameraPosition.x(),
        0.0F, 1.0F, 0.0F, -randomCameraPosition.y(),
        0.0F, 0.0F, 1.0F, -randomCameraPosition.z(),
        0.0F, 0.0F, 0.0F, 1.0F
    });
    // clang-format on

    // WHEN:
    const auto result(worldToCamera.inverse());

    // THEN:
    const Transform cameraToWorld(worldToCameraInverse, worldToCameraInverse.inverse());
    EXPECT_EQ(result, cameraToWorld);
}

} // namespace eyebeam
