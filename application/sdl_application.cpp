#include "sdl_application.h"

#include <SDL2/SDL.h>

#include <chrono>
#include <cstdint>
#include <memory>
#include <ratio>
#include <thread>

namespace eyebeam
{

namespace
{

using Clock = std::chrono::steady_clock;

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

enum class EventLoopResult
{
    QuitApp,
    ContinueLoop
};

auto pollForEvents(SDL_Event& event)
{
    auto shouldQuit = EventLoopResult::ContinueLoop;

    while (SDL_PollEvent(&event) == 1)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            shouldQuit = EventLoopResult::QuitApp;
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_q)
            {
                SDL_Event quitEvent;
                quitEvent.type = SDL_QUIT;
                SDL_PushEvent(&quitEvent);
            }
            break;
        default:
            break;
        }
    }

    return shouldQuit;
}

void yieldExtraLoopTime(const Clock::time_point& loopStartTime)
{
    constexpr auto framesPerSecond(60);
    using FrameDuration = std::chrono::duration<std::int64_t, std::ratio<1, framesPerSecond>>;
    constexpr FrameDuration frameDuration(1);

    const auto loopElapsedTime(Clock::now() - loopStartTime);
    const auto loopExtraTime(frameDuration - loopElapsedTime);

    if (loopExtraTime.count() > 0)
    {
        std::this_thread::sleep_for(loopExtraTime);
    }
}

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
    }

private:
    [[maybe_unused]] int m_argc;
    [[maybe_unused]] char** m_argv;

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
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        return AppInit::InitFailed;
    }

    return m_pAppData->createWindow();
}

void SdlApplication::render() const
{
    m_pAppData->render();
}

void SdlApplication::run()
{
    SDL_Event event;
    auto shouldContinue = EventLoopResult::ContinueLoop;

    do
    {
        const auto loopStartTime(Clock::now());
        shouldContinue = pollForEvents(event);
        render();
        yieldExtraLoopTime(loopStartTime);
    } while (shouldContinue == EventLoopResult::ContinueLoop);
}

} // namespace eyebeam
