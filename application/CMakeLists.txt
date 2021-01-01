find_package(SDL2 CONFIG REQUIRED)

add_library(application
    application.cpp
    sdl_application.cpp
)

target_link_libraries(application PUBLIC
    enable_cxx_17
    enable_warnings
    scene
    SDL2::SDL2
)

add_executable(eyebeam main.cpp)

target_link_libraries(eyebeam PRIVATE
    application
    SDL2::SDL2main
)
