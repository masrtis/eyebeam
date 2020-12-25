#ifndef INCLUDED_SDL_APPLICATION_H_
#define INCLUDED_SDL_APPLICATION_H_

#include "application.h"

#include <memory>

namespace eyebeam
{

class SdlApplication final : public Application
{
public:
    explicit SdlApplication(int argc, char** argv);
    ~SdlApplication();

    SdlApplication(const SdlApplication&) = delete;
    SdlApplication(SdlApplication&&) = delete;

    SdlApplication& operator=(const SdlApplication&) = delete;
    SdlApplication& operator=(SdlApplication&&) = delete;

    AppInit init() final;
    void render() const final;
    void run() final;

private:
    class AppImpl;

    std::unique_ptr<AppImpl> m_pAppData;
};

} // namespace eyebeam

#endif // INCLUDED_SDL_APPLICATION_H_
