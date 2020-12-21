#ifndef INCLUDED_COMPONENTS_H_
#define INCLUDED_COMPONENTS_H_

#include "constexpr_math.h"

// NOLINTNEXTLINE
#include <array>

namespace eyebeam
{

class Components
{
public:
    constexpr Components() noexcept : Components(0.0F, 0.0F, 0.0F, 0.0F)
    {
    }

    explicit constexpr Components(float x, float y, float z, float w) noexcept : m_components{x, y, z, w}
    {
    }

    constexpr auto x() const noexcept
    {
        return m_components[0];
    }

    constexpr auto y() const noexcept
    {
        return m_components[1];
    }

    constexpr auto z() const noexcept
    {
        return m_components[2];
    }

    constexpr auto w() const noexcept
    {
        return m_components[3];
    }

    auto& x() noexcept
    {
        return m_components[0];
    }

    auto& y() noexcept
    {
        return m_components[1];
    }

    auto& z() noexcept
    {
        return m_components[2];
    }

    auto& w() noexcept
    {
        return m_components[3];
    }

protected:
    ~Components() = default;

private:
    std::array<float, 4> m_components;
};

constexpr auto operator==(const Components& left, const Components& right) noexcept
{
    return areEqual(left.x(), right.x()) && areEqual(left.y(), right.y()) && areEqual(left.z(), right.z());
}

constexpr auto operator!=(const Components& left, const Components& right) noexcept
{
    return !(left == right);
}

} // namespace eyebeam

#endif // INCLUDED_COMPONENTS_H_
