###--------→ DIST ←--------------------------------------------------------------------###
BRICKGAME_DIST_ARCH := brick_game-2.0.tar.gz

BRICKGAME_DIST_FILES := brick_game gui Doxyfile play Makefile make\
 CMakeLists.txt cmake ${TEST_DIR} docs README.md

dist:
	@mkdir -p $(DIST_DIR)
	@cp -r $(BRICKGAME_DIST_FILES) $(DIST_DIR)
	@tar -czf ${BRICKGAME_DIST_ARCH} $(DIST_DIR)
	@rm -rf $(DIST_DIR)
	@echo "Dist done"