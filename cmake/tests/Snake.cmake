set(SNAKE_TEST snake_test)

file(GLOB SNAKE_TEST_FILES "test_dir/snake/*.cc" "test_dir/snake/*.hpp")

add_executable(${SNAKE_TEST} ${SNAKE_TEST_FILES})

target_compile_options(${SNAKE_TEST} PRIVATE -Wall -Werror -Wextra)

target_link_libraries(
  ${SNAKE_TEST} PRIVATE GTest::GTest GTest::Main Threads::Threads
                        GTest::gtest_main snake_back_lib_dsnake)

add_test(NAME ${SNAKE_TEST} COMMAND ${SNAKE_TEST})
