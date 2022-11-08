#include "scene_factory_json.h"

#include "scene.h"
#include "scene_resolution.h"

#include "point3.h"
#include "transform.h"
#include "vector3.h"

#include <nlohmann/json.hpp>

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace eyebeam
{

namespace
{

using Json = nlohmann::json;

auto parseJsonFromFile(std::string_view fileName)
{
    const std::filesystem::path filePath(fileName);
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        using namespace std::string_literals;
        throw std::invalid_argument("Could not open scene file "s + std::string(fileName));
    }

    Json parsedJson;
    inputFile >> parsedJson;
    return parsedJson;
}

auto readResolution(const Json& sceneJson)
{
    const auto resolutionJson(sceneJson.find("resolution"));
    return resolutionJson != sceneJson.end() ? std::make_optional<SceneResolution>(
                                                   resolutionJson->at("width").get<int>(),
                                                   resolutionJson->at("height").get<int>())
                                             : std::nullopt;
}

template <std::size_t ExpectedSize>
auto readMathArray(const Json& parent, std::string_view key)
{
    using ComponentStorage = UnalignedComponentStorage<ExpectedSize>;

    const auto value(parent.find(key));

    if (value == parent.end())
    {
        return std::optional<ComponentStorage>();
    }

    if (!value->is_array())
    {
        return std::optional<ComponentStorage>();
    }

    if (value->size() != ExpectedSize)
    {
        return std::optional<ComponentStorage>();
    }

    return std::make_optional<ComponentStorage>(value->get<ComponentStorage>());
}

auto readPoint(const Json& parent, std::string_view key)
{
    return readMathArray<3>(parent, key);
}

auto readVector(const Json& parent, std::string_view key)
{
    return readMathArray<3>(parent, key);
}

auto readCamera(const Json& sceneJson)
{
    const auto lookAtJson(sceneJson.find("camera"));
    if (lookAtJson == sceneJson.end())
    {
        return std::optional<UnalignedTransformStorage>();
    }

    const auto optionalPosition(readPoint(*lookAtJson, "position"));
    if (!optionalPosition.has_value())
    {
        return std::optional<UnalignedTransformStorage>();
    }

    const auto optionalLookAt(readPoint(*lookAtJson, "lookAt"));
    if (!optionalLookAt.has_value())
    {
        return std::optional<UnalignedTransformStorage>();
    }

    const auto optionalUp(readVector(*lookAtJson, "up"));
    if (!optionalUp.has_value())
    {
        return std::optional<UnalignedTransformStorage>();
    }

    const Point3 position(*optionalPosition);
    const Point3 lookAt(*optionalLookAt);
    const Vector3 up(*optionalUp);

    return std::make_optional<UnalignedTransformStorage>(
        Transform::lookAt(position, lookAt, up).getTransformUnaligned());
}

} // namespace

std::unique_ptr<Scene> SceneFactoryJson::buildScene(std::string_view fileName) const
{
    try
    {
        const auto startTime(std::chrono::steady_clock::now());

        const auto sceneJson(parseJsonFromFile(fileName));
        const auto resolution(readResolution(sceneJson));

        if (!resolution.has_value())
        {
            std::cerr << "Error loading resolution from " << fileName << "\n";
            return nullptr;
        }

        const auto worldToCameraTransform(readCamera(sceneJson));

        if (!worldToCameraTransform.has_value())
        {
            std::cerr << "Error loading look at transform from " << fileName << "\n";
            return nullptr;
        }

        const std::chrono::duration<double> duration(std::chrono::steady_clock::now() - startTime);
        std::cout << "Scene file parsed in " << duration.count() << " seconds \n";

        return std::make_unique<Scene>(*resolution);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return nullptr;
    }
}

} // namespace eyebeam
