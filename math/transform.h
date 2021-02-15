#ifndef INCLUDED_TRANSFORMATION_H_
#define INCLUDED_TRANSFORMATION_H_

#include "angle.h"
#include "matrix4.h"
#include "normal3.h"
#include "ray3.h"
#include "vector3.h"

#include <iosfwd>

namespace eyebeam
{

class Normal3;
class Point3;
class Ray3;

class Transform
{
public:
    constexpr Transform() = default;
    constexpr Transform(const Matrix4& matrix, const Matrix4& inverse) : m_matrix(matrix), m_inverse(inverse)
    {
    }

    explicit Transform(const AlignedMatrixStorage& elements);

    [[nodiscard]] constexpr auto inverse() const noexcept
    {
        return Transform(m_inverse, m_matrix);
    }

    [[nodiscard]] constexpr auto transpose() const noexcept
    {
        return Transform(m_matrix.transpose(), m_inverse.transpose());
    }

    [[nodiscard]] constexpr auto multiply(const Point3& p) const noexcept
    {
        return m_matrix.multiply(p);
    }

    [[nodiscard]] constexpr auto multiply(const Vector3& v) const noexcept
    {
        return m_matrix.multiply(v);
    }

    [[nodiscard]] constexpr auto multiply(const Transform& t) const noexcept
    {
        return Transform(m_matrix.multiply(t.m_matrix), t.m_inverse.multiply(m_inverse));
    }

    [[nodiscard]] Normal3 multiply(const Normal3& n) const noexcept;
    [[nodiscard]] Ray3 multiply(const Ray3& r) const noexcept;

    [[nodiscard]] static constexpr auto translate(const Vector3& deltaX) noexcept
    {
        // clang-format off
        const Matrix4 m(AlignedMatrixStorage{
            1.0F, 0.0F, 0.0F, deltaX.x(),
            0.0F, 1.0F, 0.0F, deltaX.y(),
            0.0F, 0.0F, 1.0F, deltaX.z(),
            0.0F, 0.0F, 0.0F, 1.0F});

        const Matrix4 inverse(AlignedMatrixStorage{
            1.0F, 0.0F, 0.0F, -deltaX.x(),
            0.0F, 1.0F, 0.0F, -deltaX.y(),
            0.0F, 0.0F, 1.0F, -deltaX.z(),
            0.0F, 0.0F, 0.0F, 1.0F});
        // clang-format on

        return Transform(m, inverse);
    }

    [[nodiscard]] static constexpr auto scale(float x, float y, float z) noexcept
    {
        // clang-format off
        const Matrix4 m(AlignedMatrixStorage{
            x, 0.0F, 0.0F, 0.0F,
            0.0F, y, 0.0F, 0.0F,
            0.0F, 0.0F, z, 0.0F,
            0.0F, 0.0F, 0.0F, 1.0F});

        const Matrix4 inverse(AlignedMatrixStorage{
            1.0F / x, 0.0F, 0.0F, 0.0F,
            0.0F, 1.0F / y, 0.0F, 0.0F,
            0.0F, 0.0F, 1.0F / z, 0.0F,
            0.0F, 0.0F, 0.0F, 1.0F});
        // clang-format on

        return Transform(m, inverse);
    }

    [[nodiscard]] static Transform rotateX(Radians theta);
    [[nodiscard]] static Transform rotateY(Radians theta);
    [[nodiscard]] static Transform rotateZ(Radians theta);
    [[nodiscard]] static Transform rotateAxisAngle(Vector3 axis, Radians theta);
    [[nodiscard]] static Transform lookAt(const Point3& cameraPosition, const Point3& lookAt, Vector3 up) noexcept;

    [[nodiscard]] bool isIdentity() const;

    friend bool operator==(const Transform& lhs, const Transform& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Transform& out);

private:
    Matrix4 m_matrix;
    Matrix4 m_inverse;
};

bool operator!=(const Transform& lhs, const Transform& rhs);

} // namespace eyebeam

#endif // INCLUDED_TRANSFORMATION_H_
