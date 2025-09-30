NPROC := $(shell expr $$(nproc) - 2)
ifeq ($(shell expr $(NPROC) \< 1), 1)
  NPROC := 1
endif

all: 
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug   
	@cmake --build build --parallel $(NPROC)    

# собирать для тестов
all_dbg:
	@cmake -DTEST=ON -B build -DCMAKE_BUILD_TYPE=Debug   
	@cmake --build build --parallel $(NPROC)   

install:
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug 
	@cmake --build build --target tetris_cli --parallel $(NPROC)    
	@cmake --build build --target tetris_desktop --parallel $(NPROC)    
	@cmake --build build --target snake_cli --parallel $(NPROC)    
	@cmake --build build --target snake_desktop --parallel $(NPROC)
	@echo "Install is completed"

uninstall:
	@cmake --build build --target custom_uninstall --parallel $(NPROC)   

###--------→ DVI ←--------------------------------------------------------------------###
DOXY_DIR := docs/brick_game_v2.0
dvi:
	doxygen $(DOXY_DIR)/Doxyfile

###--------→ DIST ←--------------------------------------------------------------------###
DIST_DIR := dist_dir 
BRICKGAME_DIST_ARCH := brick_game-2.0.tar.gz

BRICKGAME_DIST_FILES := brick_game gui play Makefile\
 CMakeLists.txt cmake ${TEST_DIR} docs

dist:
	@mkdir -p $(DIST_DIR)
	@cp -r $(BRICKGAME_DIST_FILES) $(DIST_DIR)
	@tar -czf ${BRICKGAME_DIST_ARCH} $(DIST_DIR)
	@rm -rf $(DIST_DIR)
	@echo "Dist done"

###--------→ TEST ←--------------------------------------------------------------------###
test: test_snake

test_snake:  
	@ctest --test-dir build -R snake --parallel $(NPROC) --output-on-failure

test_tetris:
	@ctest --test-dir build -R tetris -V --parallel $(NPROC) --output-on-failure

###--------→ COVERAGE ←--------------------------------------------------------------------###
coverage:  
	@rm -f brick_game/snake/data_base/highscore.txt
	@cmake --build build --target coverage --parallel $(NPROC)

###--------→ PLAY ←--------------------------------------------------------------------###
play_tc:
	@cmake --build build --target play_tetris_cli --parallel $(NPROC)

play_td:
	@cmake --build build --target play_tetris_desktop --parallel $(NPROC)

play_sc:
	@cmake --build build --target play_snake_cli --parallel $(NPROC)

play_sd:   
	@cmake --build build --target play_snake_desktop --parallel $(NPROC)
	

###--------→ CLANG ←---------------------------------------------------------------###
CLANG_FILES := $(shell find . \( -name '*.c' -o -name '*.h' -o -name '*.cc' -o -name '*.hpp' \))

clang_f:
	@cp ../materials/linters/.clang-format . 
	@clang-format-18 -i $(CLANG_FILES)
	@rm .clang-format
	@echo "Clang done"

###--------→ CMAKE ←---------------------------------------------------------------###
CMAKE_FILES := $(shell find . -name '*.cmake')
cmake_f: 
	@cmake-format -i $(CMAKE_FILES) CMakeLists.txt
	@echo "Cmake done"

###--------→ CLEAN ←------------------------------------------------------------###
FILES_TO_DEL := build $(DOXY_DIR)/doxygen $(BRICKGAME_DIST_ARCH)

clean: 
	@rm -rf $(FILES_TO_DEL)
	@echo "Clean done"	 

###--------→ FORMAT ←--------------------------------------------------------------------###
f: clang_f cmake_f 


###--------→ CUSTOM ←--------------------------------------------------------------------###
fcl: f clean 
	@echo "Clean and Format done"

fc: clang_f clean 
	@echo "Clean and Format done"