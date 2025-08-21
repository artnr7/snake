###--------→ DIST ←--------------------------------------------------------------------###
TETRIS_DIST_FILES := brick_game gui Doxyfile tetris_cli.c Makefile FSM.png tetris_test_dir

dist:
	@mkdir -p $(TETRIS_DIST_DIR)
	@cp -r $(TETRIS_DIST_FILES) $(TETRIS_DIST_DIR)
	@tar -czf tetris-1.0.tar.gz $(TETRIS_DIST_DIR)
	@rm -rf $(TETRIS_DIST_DIR)
	@echo "Archive done"