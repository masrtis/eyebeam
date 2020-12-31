#ifndef INCLUDED_APPLICATION_H_
#define INCLUDED_APPLICATION_H_

#include <string>

namespace eyebeam
{

enum class AppInit
{
    Succeeded,
    InitSubsystemsFailed,
    WindowCreationFailed,
    CouldNotLoadScene,
    InvalidCommandLineArguments
};

class Application
{
public:
    virtual AppInit init() = 0;
    virtual void render() const = 0;
    virtual void run() = 0;
    [[nodiscard]] virtual std::string getLastError() const = 0;

    Application() = default;

    Application(const Application&) = delete;
    Application(Application&&) = delete;

    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

protected:
    ~Application() = default;
};

} // namespace eyebeam

#endif
