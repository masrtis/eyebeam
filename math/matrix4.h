#ifndef INCLUDED_MATRIX4_H_
#define INCLUDED_MATRIX4_H_

#include "constexpr_math.h"
#include "point3.h"
#include "vector3.h"

#include <array>
#include <iosfwd>

namespace eyebeam
{

namespace impl
{

void swapRowForNonZeroDiagonal(std::array<float, 16>& toInvert, std::array<float, 16>& inverse, size_t row);

void combineRows(
    std::array<float, 16>& toInvert,
    std::array<float, 16>& inverse,
    size_t reducingRow,
    size_t combinationRow,
    float leadingElement) noexcept;

void scaleRow(std::array<float, 16>& toInvert, std::array<float, 16>& inverse, size_t row, float scalar) noexcept;

[[nodiscard]] constexpr auto getIndexFromRowColumn(size_t row, size_t column) noexcept
{
    return row * 4 + column;
}

} // namespace impl

using UnalignedMatrixStorage = std::array<float, 16>;

struct alignas(16) AlignedMatrixStorage
{
    std::array<float, 16> data;
};

class alignas(16) Matrix4
{
public:
    constexpr Matrix4() noexcept : Matrix4(buildIdentity())
    {
    }

    constexpr explicit Matrix4(const UnalignedMatrixStorage& elements) noexcept : m_elements(elements)
    {
    }

    constexpr explicit Matrix4(const AlignedMatrixStorage& elements) noexcept : m_elements(elements.data)
    {
    }

    constexpr Matrix4(
        float e00,
        float e01,
        float e02,
        float e03,
        float e10,
        float e11,
        float e12,
        float e13,
        float e20,
        float e21,
        float e22,
        float e23,
        float e30,
        float e31,
        float e32,
        float e33) noexcept
        : Matrix4(AlignedMatrixStorage{e00, e01, e02, e03, e10, e11, e12, e13, e20, e21, e22, e23, e30, e31, e32, e33})
    {
    }

    [[nodiscard]] constexpr static Matrix4 buildIdentity() noexcept
    {
        return Matrix4(AlignedMatrixStorage{
            1.0F,
            0.0F,
            0.0F,
            0.0F,
            0.0F,
            1.0F,
            0.0F,
            0.0F,
            0.0F,
            0.0F,
            1.0F,
            0.0F,
            0.0F,
            0.0F,
            0.0F,
            1.0F});
    }

    [[nodiscard]] constexpr auto transpose() const noexcept
    {
        using namespace impl;

        return Matrix4(AlignedMatrixStorage{
            m_elements[getIndexFromRowColumn(0, 0)],
            m_elements[getIndexFromRowColumn(1, 0)],
            m_elements[getIndexFromRowColumn(2, 0)],
            m_elements[getIndexFromRowColumn(3, 0)],
            m_elements[getIndexFromRowColumn(0, 1)],
            m_elements[getIndexFromRowColumn(1, 1)],
            m_elements[getIndexFromRowColumn(2, 1)],
            m_elements[getIndexFromRowColumn(3, 1)],
            m_elements[getIndexFromRowColumn(0, 2)],
            m_elements[getIndexFromRowColumn(1, 2)],
            m_elements[getIndexFromRowColumn(2, 2)],
            m_elements[getIndexFromRowColumn(3, 2)],
            m_elements[getIndexFromRowColumn(0, 3)],
            m_elements[getIndexFromRowColumn(1, 3)],
            m_elements[getIndexFromRowColumn(2, 3)],
            m_elements[getIndexFromRowColumn(3, 3)]});
    }

    [[nodiscard]] constexpr auto multiply(const Point3& rhs) const noexcept
    {
        std::array<float, 4> result = {0.0F};

        for (size_t row = 0; row < 4; ++row)
        {
            using namespace impl;
            result.at(row) = m_elements.at(getIndexFromRowColumn(row, 0)) * rhs.x() +
                             m_elements.at(getIndexFromRowColumn(row, 1)) * rhs.y() +
                             m_elements.at(getIndexFromRowColumn(row, 2)) * rhs.z() +
                             m_elements.at(getIndexFromRowColumn(row, 3));
        }

        if (!areEqual(result[3], 1.0F))
        {
            const auto homogenousReciprocal = 1.0F / result[3];
            result[0] *= homogenousReciprocal;
            result[1] *= homogenousReciprocal;
            result[2] *= homogenousReciprocal;
        }

        return Point3(result[0], result[1], result[2]);
    }

    [[nodiscard]] constexpr auto multiply(const Vector3& rhs) const noexcept
    {
        std::array<float, 3> result = {0.0F};

        for (size_t row = 0; row < 3; ++row)
        {
            using namespace impl;
            result.at(row) = m_elements.at(getIndexFromRowColumn(row, 0)) * rhs.x() +
                             m_elements.at(getIndexFromRowColumn(row, 1)) * rhs.y() +
                             m_elements.at(getIndexFromRowColumn(row, 2)) * rhs.z();
        }

        return Vector3(result[0], result[1], result[2]);
    }

    [[nodiscard]] constexpr auto multiply(const Matrix4& rhs) const noexcept
    {
        AlignedMatrixStorage result = {0.0F};

        for (size_t row = 0; row < 4; ++row)
        {
            for (size_t column = 0; column < 4; ++column)
            {
                for (size_t i = 0; i < 4; ++i)
                {
                    using namespace impl;
                    result.data.at(getIndexFromRowColumn(row, column)) +=
                        m_elements.at(getIndexFromRowColumn(row, i)) *
                        rhs.m_elements.at(getIndexFromRowColumn(i, column));
                }
            }
        }

        return Matrix4(result);
    }

    [[nodiscard]] Matrix4 inverse() const;
    [[nodiscard]] bool isEqual(const Matrix4& other) const;

    void print(std::ostream& os) const;

private:
    std::array<float, 16> m_elements;
};

bool operator==(const Matrix4& lhs, const Matrix4& rhs);
bool operator!=(const Matrix4& lhs, const Matrix4& rhs);

bool isIdentity(const Matrix4& m);

std::ostream& operator<<(std::ostream& os, const Matrix4& out);

} // namespace eyebeam

#endif // INCLUDED_MATRIX4_H_
