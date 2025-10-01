add_custom_target(
  custom_uninstall
  COMMAND rm -rf ${CMAKE_CURRENT_SOURCE_DIR}/${INSTALL_DIR}
  COMMENT "Uninstall done")
