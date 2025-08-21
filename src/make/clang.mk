###--------→ CLANG ←---------------------------------------------------------------###
# файлы для Clang
CLANG_FILES := ${shell find . -name '*.c' '*.cc' '*.h' '*.hpp'}

clang:
	@cp ../materials/linters/.clang-format . 
	@clang-format -i $(CLANG_FILES)
	@rm .clang-format
	@echo "Clang done"