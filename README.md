# eyebeam
Ray tracing experiment

## Build Info

The CMake files assume that SDL2 is available via (vcpkg)[https://github.com/Microsoft/vcpkg]. As a result, the VSCode settings that are checked in configure the vscode CMake Tools extension to use the vcpkg CMake toolchain. In order to use these settings as is, the VCPKG_ROOT environment variable should be set to the root of the vcpkg clone.
