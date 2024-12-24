# https://stackoverflow.com/questions/31969547/what-is-the-difference-between-include-directories-and-target-include-directorie

set(SOURCES main.c)
set(APP_NAME raylibapp)

# exe file
add_executable(${APP_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCES})

# libs
target_link_libraries(${APP_NAME} PRIVATE raylib)
target_link_libraries(${APP_NAME} PRIVATE gamecode)