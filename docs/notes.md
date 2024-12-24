


CMakeLists.txt work some degree
-need raylib in debug to work

runapp.bat
```
@echo off
cd build
cmake --build .
cd ..
"build/bin/Debug/raylibapp.exe"
::pause
```

https://github.com/SasLuca/raylib-cmake-template/blob/master/CMakeLists.txt

https://stackoverflow.com/questions/40739061/error-lnk1104-cannot-open-file-debug-myprojectlib-lib


https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak

https://medium.com/@TheElkantor/how-to-add-hot-reload-to-your-raylib-proj-in-c-698caa33eb74

https://stackoverflow.com/questions/78604384/how-to-link-raylib-with-hot-reloading-in-c-windows-linux-platforms

```
BUILD_SHARED_LIBS to ON
```



https://www.reddit.com/r/raylib/comments/1ejn2vk/halp_please_with_implementing_hot_reloading_in_c/

CmakeLists.txt
```
cmake_minimum_required(VERSION 3.11) 
# FetchContent is available in 3.11+
project(StarSurvivor)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) 
# QUIET or REQUIRED
if (NOT raylib_FOUND) 
# If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) 
# Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
# don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    
  endif()
endif()

## new for raylib to be linked to a shared libraryS
set_property(TARGET raylib PROPERTY  POSITION_INDEPENDENT_CODE ON)
# Our Project

file(GLOB SOURCES src/*.c)
set(SOURCES ${SOURCES})
SET(GAMESRC src/game.c src/player.c src/main_menu.c src/player_ui.c
            src/entities.c src/journal.c src/challenges.c src/roguelike.c
            src/projectile.c src/r_armour.c src/asteroid.c)
add_library(game SHARED ${SOURCES})
set_property(TARGET game PROPERTY POSITION_INDEPENDENT_CODE ON)
add_executable(${PROJECT_NAME} ${SOURCES})


#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(game PRIVATE raylib)
```