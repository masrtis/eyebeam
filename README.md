# eyebeam

C++ ray tracing experiment

## Controls

All controls are case insensitive.

- **Q** - Exits the application

## Build Info

The build system used is [CMake](https://cmake.org/). The build has been tested using Visual Studio Code using both Visual Studio 2019 and Clang 10.0.0.

### Visual Studio Code setup

#### External tools required

[CMake 3.18.4 or higher](https://cmake.org/)  
[vcpkg - build from source](https://github.com/Microsoft/vcpkg)  

##### vcpkg info

vcpkg is configured to use vcpkg manifest mode. vcpkg is configured as a submodule which will need to be updated in order to update the dependent library versions. Bootstrapping vcpkg on first time checkout may be necessary.

In order to use vcpkg in order to build with CMake, `CMAKE_TOOLCHAIN_FILE` should be set to `./vcpkg/scripts/buildsystems/vcpkg.cmake`.

##### Windows specific tools

[Visual Studio 2019 Community](https://visualstudio.microsoft.com/vs/community/) - this installs compilers that can be used by Visual Studio Code

#### External libraries required

[SDL2](https://www.libsdl.org/)  
[GTest/GMock](https://github.com/google/googletest)  
[benchmark](https://github.com/google/benchmark)  

#### Extensions used for VSCode build

Name: C/C++  
Id: ms-vscode.cpptools  
Description: C/C++ IntelliSense, debugging, and code browsing.  
Version: 1.1.3  
Publisher: Microsoft  
[VS Marketplace Link](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

Name: CMake Tools  
Id: ms-vscode.cmake-tools  
Description: Extended CMake support in Visual Studio Code  
Version: 1.5.3  
Publisher: Microsoft  
[VS Marketplace Link](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

### Linux Setup

Debian dependencies

    apt install build-essentials clang libgtest-dev libgmock-dev libbenchmark-dev

#### Compiling

Switch to Clang as the default compiler for this terminal session:

    export CC=clang
    export CXX=clang++

Then make an out-of-source build directory and run cmake to configure
the build:

    mkdir build
    cd build
    cmake ..

Then compile the project with make:

    make -j$(nproc)

Then you can run the application:

    ./application/eyebeam
