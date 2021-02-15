#include "transform.h"

#include "matrix4.h"
#include "normal3.h"
#include "point3.h"
#include "ray3.h"
#include "vector3.h"

#include <cmath>
#include <ostream>

namespace eyebeam
{

Transform::Transform(const AlignedMatrixStorage& elements) : m_matrix(elements), m_inverse(m_matrix.inverse())
{
}

Normal3 Transform::multiply(const Normal3& n) const noexcept
{
    const auto transposedInverse(m_inverse.transpose());
    return Normal3(transposedInverse.multiply(Vector3(n)));
}

Ray3 Transform::multiply(const Ray3& r) const noexcept
{
    return Ray3(m_matrix.multiply(r.origin()), m_matrix.multiply(r.direction()));
}

Transform Transform::rotateX(Radians theta)
{
    const float sinTheta = std::sin(theta);
    const float cosTheta = std::cos(theta);

    // clang-format off
    const Matrix4 m(AlignedMatrixStorage{
        1.0F, 0.0F, 0.0F, 0.0F,
        0.0F, cosTheta, -sinTheta, 0.0F,
        0.0F, sinTheta, cosTheta, 0.0F,
        0.0F, 0.0F, 0.0F, 1.0F
    });
    // clang-format on

    return Transform(m, m.transpose());
}

Transform Transform::rotateY(Radians theta)
{
    const float sinTheta = std::sin(theta);
    const float cosTheta = std::cos(theta);

    // clang-format off
    const Matrix4 m(AlignedMatrixStorage{
        cosTheta, 0.0F, sinTheta, 0.0F,
        0.0F, 1.0F, 0.0F, 0.0F,
        -sinTheta, 0.0F, cosTheta, 0.0F,
        0.0F, 0.0F, 0.0F, 1.0F
    });
    // clang-format on

    return Transform(m, m.transpose());
}

Transform Transform::rotateZ(Radians theta)
{
    const float sinTheta = std::sin(theta);
    const float cosTheta = std::cos(theta);

    // clang-format off
    const Matrix4 m(AlignedMatrixStorage{
        cosTheta, -sinTheta, 0.0F, 0.0F,
        sinTheta, cosTheta, 0.0F, 0.0F,
        0.0F, 0.0F, 1.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 1.0F
    });
    // clang-format on

    return Transform(m, m.transpose());
}

Transform Transform::rotateAxisAngle(Vector3 axis, Radians theta)
{
    normalize(axis);

    const float sinTheta = std::sin(theta);
    const float cosTheta = std::cos(theta);

    const Matrix4 m(AlignedMatrixStorage{
        axis.x() * axis.x() + (1.0F - axis.x() * axis.x()) * cosTheta,
        axis.x() * axis.y() * (1.0F - cosTheta) - axis.z() * sinTheta,
        axis.x() * axis.z() * (1.0F - cosTheta) + axis.y() * sinTheta,
        0.0F,
        axis.x() * axis.y() * (1.0F - cosTheta) + axis.z() * sinTheta,
        axis.y() * axis.y() + (1.0F - axis.y() * axis.y()) * cosTheta,
        axis.y() * axis.z() * (1.0F - cosTheta) - axis.x() * sinTheta,
        0.0F,
        axis.x() * axis.z() * (1.0F - cosTheta) - axis.y() * sinTheta,
        axis.y() * axis.z() * (1.0F - cosTheta) + axis.x() * sinTheta,
        axis.z() * axis.z() + (1.0F - axis.z() * axis.z()) * cosTheta,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    return Transform(m, m.transpose());
}

Transform Transform::lookAt(const Point3& cameraPosition, const Point3& lookAt, Vector3 up) noexcept
{
    Vector3 viewingDirection(lookAt - cameraPosition);
    normalize(viewingDirection);

    normalize(up);

    Vector3 left(cross(up, viewingDirection));
    normalize(left);

    const Vector3 newUp(cross(viewingDirection, left));

    // clang-format off
    Matrix4 m(AlignedMatrixStorage{
        left.x(), newUp.x(), viewingDirection.x(), cameraPosition.x(),
        left.y(), newUp.y(), viewingDirection.y(), cameraPosition.y(),
        left.z(), newUp.z(), viewingDirection.z(), cameraPosition.z(),
        0.0F, 0.0F, 0.0F, 1.0F
    });
    // clang-format on

    return Transform(m, m.inverse());
}

bool Transform::isIdentity() const
{
    return eyebeam::isIdentity(m_matrix) && eyebeam::isIdentity(m_inverse);
}

bool operator==(const Transform& lhs, const Transform& rhs)
{
    return lhs.m_matrix == rhs.m_matrix && lhs.m_inverse == rhs.m_inverse;
}

bool operator!=(const Transform& lhs, const Transform& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Transform& out)
{
    os << "Transform:\n" << out.m_matrix << "\n\nInverse:\n" << out.m_inverse;
    return os;
}

} // namespace eyebeam
