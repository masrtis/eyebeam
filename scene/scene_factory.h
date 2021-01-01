#ifndef INCLUDED_SCENE_FACTORY_H_
#define INCLUDED_SCENE_FACTORY_H_

#include <memory>
#include <string_view>

namespace eyebeam
{

class Scene;

class SceneFactory
{
public:
    SceneFactory() = default;
    virtual ~SceneFactory() = default;

    SceneFactory(const SceneFactory&) = delete;
    SceneFactory(SceneFactory&&) = delete;

    SceneFactory& operator=(const SceneFactory&) = delete;
    SceneFactory& operator=(SceneFactory&&) = delete;

    [[nodiscard]] virtual std::unique_ptr<Scene> buildScene(std::string_view fileName) const = 0;
};

} // namespace eyebeam

#endif // INCLUDED_SCENE_FACTORY_H_
