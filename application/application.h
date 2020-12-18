#ifndef INCLUDED_APPLICATION_H_
#define INCLUDED_APPLICATION_H_

namespace eyebeam
{

enum class AppInit
{
    Succeeded,
    InitFailed,
    WindowCreationFailed
};

class Application
{
public:
    virtual AppInit init() = 0;
    virtual void render() const = 0;

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
