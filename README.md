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

##### Windows specific tools

[Visual Studio 2019 Community](https://visualstudio.microsoft.com/vs/community/) - this installs compilers that can be used by Visual Studio Code

#### External libraries required

[SDL2](https://www.libsdl.org/)  
[GTest/GMock](https://github.com/google/googletest)  
[benchmark](https://github.com/google/benchmark)  

#### Extensions used for build

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

#### Environment Variables required

`VCPKG_ROOT` should be set to the root of the vcpkg clone locally.

The CMake files assume that [SDL2](https://www.libsdl.org/) is available via [vcpkg](https://github.com/Microsoft/vcpkg). As a result, the VSCode settings that are checked in configure the CMake Tools extension to use the vcpkg CMake toolchain. In order to use these settings as is, the `VCPKG_ROOT` environment variable should be set to the root of the vcpkg clone.

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
