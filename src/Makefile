all: 
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug   
	
install:
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug
	@cmake --build build --target tetris_cli --parallel $(nproc)    
	@cmake --build build --target tetris_desktop --parallel $(nproc)    
	@cmake --build build --target snake_cli --parallel $(nproc)    
	@cmake --build build --target snake_desktop --parallel $(nproc)
	@echo "Install is completed"

uninstall:
	@cmake --build build --target custom_uninstall --parallel $(nproc)   

###--------→ CLEAN ←------------------------------------------------------------###
FILES_TO_DEL := build dist_dir coverage 

clean: 
	@rm -rf $(FILES_TO_DEL)
	@echo "Clean done"	 

###--------→ DVI ←--------------------------------------------------------------------###
dvi:
	doxygen

###--------→ DIST ←--------------------------------------------------------------------###
BRICKGAME_DIST_ARCH := brick_game-2.0.tar.gz

BRICKGAME_DIST_FILES := brick_game gui Doxyfile play Makefile\
 CMakeLists.txt cmake ${TEST_DIR} docs README.md

dist:
	@mkdir -p $(DIST_DIR)
	@cp -r $(BRICKGAME_DIST_FILES) $(DIST_DIR)
	@tar -czf ${BRICKGAME_DIST_ARCH} $(DIST_DIR)
	@rm -rf $(DIST_DIR)
	@echo "Dist done"

###--------→ TEST ←--------------------------------------------------------------------###
test:
	@cmake --build build --target run_snake_test --parallel $(nproc)    

###--------→ PLAY ←--------------------------------------------------------------------###
play_tc:
	@cmake --build build --target play_tetris_cli --parallel $(nproc)

play_td:
	@cmake --build build --target play_tetris_desktop --parallel $(nproc)

play_sc:
	@cmake --build build --target play_snake_cli --parallel $(nproc)

play_sd:
	@cmake --build build --target play_snake_desktop --parallel $(nproc)
	
###--------→ REBUILD ←--------------------------------------------------------------------###
r: 
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug   
	@cmake --build build --target clean --parallel $(nproc)    


###--------→ CLANG ←---------------------------------------------------------------###
CLANG_FILES := $(shell find . \( -name '*.c' -o -name '*.h' -o -name '*.cc' -o -name '*.hpp' \))

clang_f:
	@cp ../materials/linters/.clang-format . 
	@clang-format -i $(CLANG_FILES)
	@rm .clang-format
	@echo "Clang done"

###--------→ CMAKE ←---------------------------------------------------------------###
CMAKE_FILES := $(shell find . -name '*.cmake')
cmake_f: 
	@cmake-format -i $(CMAKE_FILES) CMakeLists.txt
	@echo "Cmake done"

###--------→ FORMAT ←--------------------------------------------------------------------###
f: clang_f cmake_f 

cclean: clean f
	@echo "Clean and Format done"