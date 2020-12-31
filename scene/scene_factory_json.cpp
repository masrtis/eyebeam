#include "scene_factory_json.h"

#include "scene.h"
#include "scene_resolution.h"

#include <nlohmann/json.hpp>

#include <filesystem>
#include <fstream>
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

} // namespace

std::unique_ptr<Scene> SceneFactoryJson::buildScene(std::string_view fileName) const
{
    try
    {
        const auto sceneJson(parseJsonFromFile(fileName));
        const auto resolution(readResolution(sceneJson));

        if (!resolution.has_value())
        {
            return nullptr;
        }

        return std::make_unique<Scene>(*resolution);
    }
    catch (const std::exception& e)
    {
        return nullptr;
    }
}

} // namespace eyebeam
