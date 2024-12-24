# https://stackoverflow.com/questions/42744315/cmake-with-subdirectories
# https://stackoverflow.com/questions/6891447/why-is-a-variable-value-not-available-after-add-subdirectory-ing-a-cmakelists-tx
message(STATUS "==== LIBS HERE! ====")
message(STATUS "FROM TOP :: TEST_LIB :: >> ${TEST_LIB} ")
set(TEST_LIB "hello lib" PARENT_SCOPE)
message(STATUS "FROM SUB :: TEST_LIB :: >> ${TEST_LIB}")

# libaray
add_subdirectory(gamecode)