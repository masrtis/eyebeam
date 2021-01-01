#include "scene_factory.h"

#include <string_view>

namespace eyebeam
{

class Scene;

class SceneFactoryJson final : public SceneFactory
{
public:
    SceneFactoryJson() = default;
    ~SceneFactoryJson() final = default;

    SceneFactoryJson(const SceneFactoryJson&) = delete;
    SceneFactoryJson(SceneFactoryJson&&) = delete;

    SceneFactoryJson& operator=(const SceneFactoryJson&) = delete;
    SceneFactoryJson& operator=(SceneFactoryJson&&) = delete;

    [[nodiscard]] std::unique_ptr<Scene> buildScene(std::string_view fileName) const override;

private:
};

} // namespace eyebeam
