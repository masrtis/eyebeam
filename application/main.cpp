#include "application.h"
#include "sdl_application.h"

#include <SDL2/SDL.h>

#include <iostream>

int main(int argc, char** argv)
{
    eyebeam::SdlApplication app(argc, argv);

    const auto initResult = app.init();

    if (initResult == eyebeam::AppInit::InitFailed)
    {
        std::cerr << "Could not initialize sdl2: " << SDL_GetError() << "\n";
        return 1;
    }

    if (initResult == eyebeam::AppInit::WindowCreationFailed)
    {
        std::cerr << "Could not create window: " << SDL_GetError() << "\n";
        return 1;
    }

    app.render();

    return 0;
}
