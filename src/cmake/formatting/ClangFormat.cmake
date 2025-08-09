file(GLOB_RECURSE CLANG_FILES "*.c" "*.h" "*.cc" "*.hpp")

add_custom_target(
  clf
  COMMAND clang-format -i ${CLANG_FILES} 
  COMMENT "clang-f done"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
