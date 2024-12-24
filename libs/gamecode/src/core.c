
#include <stdio.h>
#include <stdbool.h> 
#include "core.h"
#include "raylib.h"
// #define RAYLIB_IMPLEMENTATION 
// #include "raygui.h"

void test_i(){
  printf("Hello world!\n");
}

void core_create_window(){
  printf("init window!\n");
  InitWindow(600, 480, "test");
  printf(" === SET FPS === \n");
  //SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
}

// void core_create_window(
//     const unsigned short in_width,
//     const unsigned short in_height//,
//     //const char* in_title
// ){

//     //InitWindow(in_width, in_height, in_title);
//     InitWindow(in_width, in_height, "test");
// }
void core_execute_loop(){
  BeginDrawing();
  ClearBackground(RED);
//   // if(GuiButton((Rectangle){ 500, 200, 250, 60 }, "TEST BUTTON")) {
//   //     puts("Button pressed\n");
//   // }
  EndDrawing();
}
bool core_window_should_close(){
  return WindowShouldClose();
}

void core_close_window(){
  CloseWindow();
}