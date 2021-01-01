#ifndef INCLUDED_SCENE_H_
#define INCLUDED_SCENE_H_

#include "scene_resolution.h"

namespace eyebeam
{

class Scene
{
public:
    explicit constexpr Scene(const SceneResolution& resolution) : m_resolution(resolution)
    {
    }

    [[nodiscard]] constexpr auto height() const noexcept
    {
        return m_resolution.height();
    }

    [[nodiscard]] constexpr auto width() const noexcept
    {
        return m_resolution.width();
    }

private:
    SceneResolution m_resolution;
};

} // namespace eyebeam

#endif // INCLUDED_SCENE_H_
