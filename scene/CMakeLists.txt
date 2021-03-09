find_package(nlohmann_json CONFIG REQUIRED)

add_library(scene
    scene.cpp
    scene_factory.cpp
    scene_factory_json.cpp
    scene_resolution.cpp
)

target_include_directories(scene PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(scene PRIVATE
    enable_cxx_17
    enable_warnings
)

target_link_libraries(scene PUBLIC
    math
    nlohmann_json::nlohmann_json
)
