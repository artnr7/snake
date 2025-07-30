  add_custom_target(
    clang-format-fix
    COMMAND ${CLANG_FORMAT} --style=Google -i ${LIB_SOURCE_FILES}
            ${TEST_SOURCE_FILES}
    COMMENT "Formatting code with clang-format (Google Style)"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})