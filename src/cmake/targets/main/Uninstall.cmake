add_custom_target(
  custom_uninstall
  COMMAND rm -rf ${INSTALL_DIR}
  COMMENT "Uninstall done")
