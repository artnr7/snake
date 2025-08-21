file(GLOB_RECURSE CMAKE_FILES "cmake/*.cmake" "CMakeLists.txt")
add_custom_target(
  cmake_f
  COMMAND cmake-format -i ${CMAKE_FILES}
  COMMENT cmake-format
  done)
