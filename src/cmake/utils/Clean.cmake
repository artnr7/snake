file(GLOB_RECURSE CLEAN_FILES coverage build tetris_play)
add_custom_target(
  clean
  COMMAND rm -rf ${CLEAN_FILES}
  COMMENT clean
  done)
