// #ifndef CORE_H_
// #define CORE_H_
#pragma once

#include <stdbool.h>//add this for bool

// #if defined(_WIN32) && defined(BUILD_LIBTYPE_SHARED)
//     #define CORE __declspec(dllexport) // We are building core as a Win32 shared library (.dll)
// #elif defined(_WIN32) && defined(USE_CORE_LIB_SHARED)
//     #define CORE __declspec(dllimport) // We are using core as a Win32 shared library (.dll)
// #else
//     #define CORE // We are building or using core as a static library
// #endif

//#include "raylib.h"
// typedef struct GameState
// {
//     int veryCoolGameData;
// } GameState;

extern void test_i();

extern void core_create_window();

// extern void core_create_window(
//     const unsigned short in_width,
//     const unsigned short in_height//,
//     //const char* in_title
// );
extern void core_execute_loop();
//extern bool core_window_should_close();
extern bool core_window_should_close();
extern void core_close_window();

//#endif // CORE_H_