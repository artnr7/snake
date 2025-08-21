add_custom_target(
  install
  COMMAND clean
  COMMAND clf
  COMMAND mkdir snake_install_dir
  COMMAND snake_back_lib_dsnake)
