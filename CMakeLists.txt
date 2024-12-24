# https://stackoverflow.com/questions/15694347/installing-additional-files-with-cmake
# https://stackoverflow.com/questions/34799916/copy-file-from-source-directory-to-binary-directory-using-cmake
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
# https://github.com/raysan5/raylib/blob/master/projects/CMake/CMakeLists.txt
# 
cmake_minimum_required(VERSION 3.10)
PROJECT(rl_app C)

set(CMAKE_C_STANDARD 11) # c language
#set(CMAKE_CXX_STANDARD 17)

# set where the compiled files goes
# output > build\bin\Debug
# for lib and binary test
set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_BUILD_TYPE Release)

message(STATUS " === BUILD TYPE: ${CMAKE_BUILD_TYPE} === ")

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

# for share libaray 
#set(BUILD_SHARED_LIBS ON)
#option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
set(BUILD_SHARED_LIBS ON)

# Dependencies
set(RAYLIB_VERSION 5.5)
#check if there folder exist
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    FetchContent_MakeAvailable(raylib)
    #add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

#message(STATUS "init RAYGUI_VERSION")
#message(STATUS "BUILD_SHARED_LIBS:: ${BUILD_SHARED_LIBS}")

# set(RAYGUI_VERSION 4.0)
# find_package(raygui ${RAYGUI_VERSION} QUIET) # QUIET or REQUIRED
# if (NOT raygui_FOUND) # If there's none, fetch and build raylib
#   include(FetchContent)
#   FetchContent_Declare(
#     raygui
#     DOWNLOAD_EXTRACT_TIMESTAMP OFF
#     URL https://github.com/raysan5/raygui/archive/refs/tags/${RAYGUI_VERSION}.tar.gz
#   )
#   FetchContent_GetProperties(raygui)
#   if (NOT raygui_POPULATED) # Have we downloaded raylib yet?
#     set(FETCHCONTENT_QUIET NO)
#     FetchContent_MakeAvailable(raygui)
#     set(RAYGUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
#     include_directories(${raygui_SOURCE_DIR}/src) #src file
#   endif()
# endif()
#[[

]]

# message(STATUS "CMAKE_CURRENT_BINARY_DIR:: ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR:: ${CMAKE_CURRENT_SOURCE_DIR}")

# This is the main part:
#set(SOURCES rl_window.c)
# set(SOURCES main.c)
# set(APP_NAME raylibapp)

# share lib for hot reload
#file(GLOB CORE_SRCS "src/*.h" "src/*.c") #not recommend cache and will fail if there no change.

add_subdirectory(libs)


set(GAMECODE_PATH "libs/gamecode")
set(GAMECODE_SRCS
   "${GAMECODE_PATH}/src/core.c"
   "${GAMECODE_PATH}/include/core.h"
)

#install(TARGETS MyExe RUNTIME DESTINATION bin)

# message(STATUS "CORE_SRCS:> ${CORE_SRCS}")
# message(STATUS "CMAKE_INSTALL_INCLUDEDIR:> ${CMAKE_INSTALL_INCLUDEDIR}")

# works
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/core.h
#      DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_library(gamecode SHARED src/core.c src/core.h)
#add_library(gamecode SHARED ${GAMECODE_SRCS})
add_library(gamecode STATIC ${GAMECODE_SRCS}) #share lib ???
#add_library(gamecode MODULE  ${GAMECODE_SRCS}) # test fail
target_include_directories(gamecode PUBLIC ${raylib_SOURCE_DIR}/src) # needed
#target_include_directories(gamecode PUBLIC ${raygui_SOURCE_DIR}/src) 
#target_link_libraries(gamecode PUBLIC raylib) # test
#target_link_libraries(gamecode PRIVATE raylib) # test


#add custom target copy
# add_custom_target(copy)
# add_custom_command(#ok
#   TARGET copy
#   POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/include # create folder
#   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/core.h ${CMAKE_CURRENT_SOURCE_DIR}/include/core.h #copy file
# )

set(SOURCES apps/main.c)
set(APP_NAME raylibapp)

# exe file
add_executable(${APP_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCES})
# copy header file 
#add_dependencies(${APP_NAME} copy)
#include dir header
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${GAMECODE_PATH}/include") #lib share
# libs
target_link_libraries(${APP_NAME} PRIVATE raylib)
target_link_libraries(${APP_NAME} PRIVATE gamecode)
