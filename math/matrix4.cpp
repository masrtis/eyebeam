#include "matrix4.h"

#include <algorithm>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace eyebeam
{

namespace impl
{

void swapRowForNonZeroDiagonal(std::array<float, 16>& toInvert, std::array<float, 16>& inverse, size_t row)
{
    float element; // NOLINT(cppcoreguidelines-init-variables) - this is initialized at the start of the for loop below
    auto rowUnderneath = row;
    for (; rowUnderneath < 4; ++rowUnderneath)
    {
        element = toInvert.at(getIndexFromRowColumn(rowUnderneath, row));
        if (!areEqual(element, 0.0F))
        {
            break;
        }
    }

    if (rowUnderneath == 4)
    {
        throw std::runtime_error("Matrix4::inverse() called on matrix with no inverse");
    }

    if (rowUnderneath != row)
    {
        for (size_t swapColumn = 0; swapColumn < 4; ++swapColumn)
        {
            const auto originalRowIndex = getIndexFromRowColumn(row, swapColumn);
            const auto swapRowIndex = getIndexFromRowColumn(rowUnderneath, swapColumn);
            std::swap(toInvert.at(originalRowIndex), toInvert.at(swapRowIndex));
            std::swap(inverse.at(originalRowIndex), inverse.at(swapRowIndex));
        }
    }
}

void combineRows(
    std::array<float, 16>& toInvert,
    std::array<float, 16>& inverse,
    size_t reducingRow,
    size_t combinationRow,
    float leadingElement) noexcept
{
    const auto toZero = toInvert.at(getIndexFromRowColumn(combinationRow, reducingRow));
    const auto scalar = -toZero / leadingElement;
    for (size_t combinationColumn = 0; combinationColumn < 4; ++combinationColumn)
    {
        const auto reducingRowIndex = getIndexFromRowColumn(reducingRow, combinationColumn);
        const auto combinationIndex = getIndexFromRowColumn(combinationRow, combinationColumn);
        const auto newIdentityElement = scalar * toInvert.at(reducingRowIndex) + toInvert.at(combinationIndex);
        const auto newInverseElement = scalar * inverse.at(reducingRowIndex) + inverse.at(combinationIndex);

        toInvert.at(combinationIndex) = newIdentityElement;
        inverse.at(combinationIndex) = newInverseElement;
    }
}

void scaleRow(std::array<float, 16>& toInvert, std::array<float, 16>& inverse, size_t row, float scalar) noexcept
{
    for (size_t scaleColumn = 0; scaleColumn < 4; ++scaleColumn)
    {
        const auto index = getIndexFromRowColumn(row, scaleColumn);
        toInvert.at(index) *= scalar;
        inverse.at(index) *= scalar;
    }
}

} // namespace impl

Matrix4 Matrix4::inverse() const
{
    using namespace impl;

    Matrix4 toInvert(*this);
    Matrix4 inverse;

    for (size_t row = 0; row < 4; ++row)
    {
        swapRowForNonZeroDiagonal(toInvert.m_elements, inverse.m_elements, row);
        auto leadingElement = toInvert.m_elements.at(getIndexFromRowColumn(row, row));

        for (size_t lowerRow = row + 1; lowerRow < 4; ++lowerRow)
        {
            combineRows(toInvert.m_elements, inverse.m_elements, row, lowerRow, leadingElement);
            leadingElement = toInvert.m_elements.at(getIndexFromRowColumn(row, row));
        }

        // scale current row so leading 1 is present
        scaleRow(toInvert.m_elements, inverse.m_elements, row, 1.0F / leadingElement);
    }

    // convert to reduced row echelon form (now all of the diagonals are ones)
    for (size_t row = 3; row > 0; --row)
    {
        for (size_t upperRow = row - 1; upperRow < 4; --upperRow)
        {
            combineRows(toInvert.m_elements, inverse.m_elements, row, upperRow, 1.0F);
        }
    }

    return inverse;
}

bool Matrix4::isEqual(const Matrix4& other) const
{
    return std::equal(begin(m_elements), end(m_elements), begin(other.m_elements), end(other.m_elements), areEqual);
}

void Matrix4::print(std::ostream& os) const
{
    std::ostream_iterator<float> outStreamIter(os, " ");

    for (size_t row = 0; row < 4; ++row)
    {
        os << "[ ";

        const auto rowOffset = row * 4;
        outStreamIter = std::copy(begin(m_elements) + rowOffset, begin(m_elements) + rowOffset + 4, outStreamIter);

        os << ']';

        if (row < 3)
        {
            os << '\n';
        }
    }
}

bool operator==(const Matrix4& lhs, const Matrix4& rhs)
{
    return lhs.isEqual(rhs);
}

bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
{
    return !(lhs == rhs);
}

bool isIdentity(const Matrix4& m)
{
    return m.isEqual(Matrix4());
}

std::ostream& operator<<(std::ostream& os, const Matrix4& out)
{
    out.print(os);
    return os;
}

} // namespace eyebeam
