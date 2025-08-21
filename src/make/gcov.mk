###--------→ GCOV ←--------------------------------------------------------------------###
TETRIS_GCOV_DIRS := coverage_report gcov_report_dir coverage.info

gcov_report: clean 
	@mkdir gcov_report_dir
	@$(GCC) $(TETRIS_BACK_C_FILES) $(TETRIS_TEST_FILES) $(TETRIS_TEST_FLAGS)	--coverage -o gcov_report_dir/gcov_test
	./gcov_report_dir/gcov_test
	geninfo --ignore-errors mismatch --ignore-errors gcov . -o coverage.info
	genhtml coverage.info -o coverage_report
	@echo "GCOV done"