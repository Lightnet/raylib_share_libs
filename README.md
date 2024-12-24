# raylib_share_libs

# license: MIT

# Information:
  This is for raylib cmake build test. For share libs in debug.

  For trying to get lib off load on execute application. As well to test hot reload.

  Note that pointer required some c programing.

  By using the bat build script to compile and run application.

# test build:
 Note I am just testing files loaded correct for dlls file.


# build:
build.bat
```
@echo off
set mybuild=build
if not exist %mybuild% (mkdir %mybuild%)
cd build
cmake ..
```
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