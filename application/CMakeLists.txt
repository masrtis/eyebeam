find_package(SDL2 CONFIG REQUIRED)

add_library(application
    application.cpp
    sdl_application.cpp
)

target_link_libraries(application PUBLIC
    SDL2::SDL2
)

target_compile_features(application PUBLIC cxx_std_17)

add_executable(eyebeam main.cpp)

target_link_libraries(eyebeam PRIVATE
    application
    SDL2::SDL2main
)
