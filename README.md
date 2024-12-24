# raylib_share_libs

# License: MIT

# Created by: Lightnet

# Tested:
 * Windows 10 64 bit

# Build type:
  * Program C Language 

# Required:
 * cmake version 3.31.1
 * Visual Studio Community or Raylib tool dev.
 * 

  CMake will find build tool for the current OS.

# Information:
  This is for raylib cmake build test. For share libraries in debug.

  To use dll libraries load from execute application to test hot reload. Not tested yet.

  Note that pointer required some c programing. For storage variable as it need to reload dll libraries.

  By using the bat build script to compile and run application.

# Test build:
 Note I am just testing files loaded correct for libraries dlls file.

# Layout:
  Need to better layout files structure for easy to read and better way to setup links.

# Build:
build.bat
```
@echo off
set mybuild=build
if not exist %mybuild% (mkdir %mybuild%)
cd build
cmake ..
```
  Check for folder build if exist else create folder.

setup build
# compile:
runapp.bat
```
@echo off
cd build
cmake --build .
cd ..
"build/bin/Debug/raylibapp.exe"
::pause
```

# Links refs:
 * https://www.raylib.com/
 * https://github.com/raysan5/raylib
 * https://cmake.org/


# Variables notes:
 * https://stackoverflow.com/questions/6891447/why-is-a-variable-value-not-available-after-add-subdirectory-ing-a-cmakelists-tx

CMakeLists.txt
```
set(TEST_VAR "Main Test")
message(STATUS "FROM TOP :: TEST_VAR :: >> ${TEST_VAR} ")
add_subdirectory(libs)
message(STATUS "FROM TOP :: TEST_VAR :: >> ${TEST_VAR} ")
```
libs/CMakeLists.txt

```
message(STATUS "FROM TOP :: TEST_VAR :: >> ${TEST_VAR} ")
set(TEST_LIB "hello lib" PARENT_SCOPE)
message(STATUS "FROM TOP :: TEST_VAR :: >> ${TEST_VAR} ")
```