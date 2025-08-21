CMAKE_FORMAT_FILES := ${shell find . -name '*.cmake'}

cmake_f:
	@cmake-format -i ${CMAKE_FORMAT_FILES}  CMakeLists.txt