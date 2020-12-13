#include "sdl_application.h"

#include <SDL2/SDL.h>

#include <memory>

namespace eyebeam
{

namespace
{

struct WindowDeleter
{
    constexpr void operator()(SDL_Window* window) const
    {
        if (window != nullptr)
        {
            SDL_DestroyWindow(window);
        }
    }
};

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

} // namespace

class SdlApplication::AppImpl
{
public:
    explicit AppImpl(int argc, char** argv) : m_argc(argc), m_argv(argv)
    {
    }

    auto createWindow()
    {
        m_window.reset(SDL_CreateWindow(
            "eyebeam",
            SDL_WINDOWPOS_UNDEFINED, // NOLINT(hicpp-signed-bitwise)
            SDL_WINDOWPOS_UNDEFINED, // NOLINT(hicpp-signed-bitwise)
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN));

        if (m_window == nullptr)
        {
            return AppInit::WindowCreationFailed;
        }

        return AppInit::Succeeded;
    }

    auto render() const
    {
        auto* const screenSurface = SDL_GetWindowSurface(m_window.get());

        constexpr auto red = 0xFF;
        constexpr auto green = 0xFF;
        constexpr auto blue = 0xFF;
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, red, green, blue));
        SDL_UpdateWindowSurface(m_window.get());

        constexpr auto delayTime = 2000;
        SDL_Delay(delayTime);
    }

private:
    int m_argc;
    char** m_argv;

    std::unique_ptr<SDL_Window, WindowDeleter> m_window = nullptr;
};

SdlApplication::SdlApplication(int argc, char** argv) : m_pAppData(std::make_unique<AppImpl>(argc, argv))
{
}

SdlApplication::~SdlApplication()
{
    m_pAppData.reset();
    if (SDL_WasInit(0) != 0)
    {
        SDL_Quit();
    }
}

AppInit SdlApplication::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return AppInit::InitFailed;
    }

    return m_pAppData->createWindow();
}

void SdlApplication::render() const
{
    m_pAppData->render();
}

} // namespace eyebeam