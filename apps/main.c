#include <stdio.h>
#include "core.h"

int main() {
  #if defined(CORE_USE_LIBTYPE_SHARED)
  printf("CORE_USE_LIBTYPE_SHARED!");
  #endif
  // printf() displays the string inside quotation
  printf("Hello, main!\n");
  test_i();

  core_create_window();
   

  //core_init_window(1280, 720, "Test"); // 1280x720 window named "Test"
  // core_init_window(1280, 720); // 1280x720 window named "Test"
  while(!core_window_should_close()){
    core_execute_loop();
  }
  core_close_window();

  return 0;
}