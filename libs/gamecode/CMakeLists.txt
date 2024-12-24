# https://stackoverflow.com/questions/31969547/what-is-the-difference-between-include-directories-and-target-include-directorie
# https://stackoverflow.com/questions/13703647/how-to-properly-add-include-directories-with-cmake
# 

message(STATUS "==== LIB GAME CODE! ====")

#set(GAMECODE_PATH "libs/gamecode")
set(GAMECODE_PATH "")
set(GAMECODE_SRCS
   "src/core.c"
   "include/core.h"
)

message(STATUS "LIB GAME CORE :: CMAKE_CURRENT_SOURCE_DIR::>> ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(gamecode STATIC ${GAMECODE_SRCS}) #share lib ???
target_include_directories(gamecode PUBLIC ${raylib_SOURCE_DIR}/src) # needed
target_include_directories(gamecode PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include") #lib include header

# Tests
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include") #lib include header
#target_include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include") #lib include header




