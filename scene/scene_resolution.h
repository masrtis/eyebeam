#ifndef INCLUDED_SCENE_RESOLUTION_H_
#define INCLUDED_SCENE_RESOLUTION_H_

#include <algorithm>

namespace eyebeam
{

class SceneResolution
{
public:
    constexpr SceneResolution(int width, int height) noexcept
        : m_width(std::max(width, 1))
        , m_height(std::max(height, 1))
    {
    }

    [[nodiscard]] constexpr auto width() const noexcept
    {
        return m_width;
    }

    [[nodiscard]] constexpr auto height() const noexcept
    {
        return m_height;
    }

private:
    int m_width;
    int m_height;
};

} // namespace eyebeam

#endif // INCLUDED_SCENE_RESOLUTION_H_
