#include "application.h"
#include "sdl_application.h"

#include <iostream>

// NOLINTNEXTLINE(bugprone-exception-escape)
int main(int argc, char** argv)
{
    eyebeam::SdlApplication app(argc, argv);

    const auto initResult = app.init();

    switch (initResult)
    {
    case eyebeam::AppInit::InitSubsystemsFailed:
        std::cerr << "Could not initialize sdl2: " << app.getLastError() << "\n";
        return 1;
    case eyebeam::AppInit::WindowCreationFailed:
        std::cerr << "Could not create window: " << app.getLastError() << "\n";
        return 1;
    case eyebeam::AppInit::CouldNotLoadScene:
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        std::cerr << "Could not load scene file " << argv[1] << "\n";
        return 1;
    case eyebeam::AppInit::InvalidCommandLineArguments:
        std::cerr << "Usage: eyebeam <pathToSceneFile>\n";
        return 1;
    case eyebeam::AppInit::Succeeded:
        break;
    }

    app.run();

    return 0;
}
