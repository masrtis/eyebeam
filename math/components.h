#ifndef INCLUDED_COMPONENTS_H_
#define INCLUDED_COMPONENTS_H_

#include "constexpr_math.h"

// NOLINTNEXTLINE
#include <array>

namespace eyebeam
{

template <size_t Size>
using UnalignedComponentStorage = std::array<float, Size>;

class alignas(16) Components
{
public:
    constexpr Components() noexcept : Components(0.0F, 0.0F, 0.0F, 0.0F)
    {
    }

    explicit constexpr Components(float x, float y, float z, float w) noexcept : m_components{x, y, z, w}
    {
    }

    explicit constexpr Components(const std::array<float, 4>& components) noexcept : m_components(components)
    {
    }

    constexpr Components(const Components&) = default;
    constexpr Components(Components&&) = default;

    constexpr Components& operator=(const Components&) = default;
    constexpr Components& operator=(Components&&) = default;

    [[nodiscard]] constexpr auto x() const noexcept
    {
        return m_components[0];
    }

    [[nodiscard]] constexpr auto y() const noexcept
    {
        return m_components[1];
    }

    [[nodiscard]] constexpr auto z() const noexcept
    {
        return m_components[2];
    }

    [[nodiscard]] constexpr auto w() const noexcept
    {
        return m_components[3];
    }

    [[nodiscard]] auto& x() noexcept
    {
        return m_components[0];
    }

    [[nodiscard]] auto& y() noexcept
    {
        return m_components[1];
    }

    [[nodiscard]] auto& z() noexcept
    {
        return m_components[2];
    }

    [[nodiscard]] auto& w() noexcept
    {
        return m_components[3];
    }

protected:
    ~Components() = default;

private:
    std::array<float, 4> m_components;
};

constexpr auto operator==(const Components& left, const Components& right)
{
    return areEqual(left.x(), right.x()) && areEqual(left.y(), right.y()) && areEqual(left.z(), right.z());
}

constexpr auto operator!=(const Components& left, const Components& right)
{
    return !(left == right);
}

} // namespace eyebeam

#endif // INCLUDED_COMPONENTS_H_
