# Build

### Standard Build Targets
``` make all```

Configures the project and builds all targets

```make all_dbg```

Configures with Debug build type and testing enabled (-DTEST=ON)

```make install```


```make uninstall```

If you want to uninstall Brickgame

Documentation Generation
make dvi
Runs Doxygen to generate documentation based on the configuration file located in docs/brick_game_v2.0/Doxyfile.

Distribution Packaging
make dist
Packages source files, documentation, and build scripts into a tar.gz archive brick_game-2.0.tar.gz.

Testing
make test
Runs all tests with the label "snake".

make test_snake
Runs snake-related tests with output on failure.

make test_tetris
Runs tetris-related tests verbosely.

Code Coverage
make coverage
Cleans highscore data file, then builds the coverage target to generate code coverage reports.

Play Targets
make play_tc — Run Tetris CLI target

make play_td — Run Tetris Desktop target

make play_sc — Run Snake CLI target

make play_sd — Run Snake Desktop target

Code Formatting
make clang_f
Formats all C/C++ source and header files using clang-format.

make cmake_f
Formats CMake files using cmake-format.

make f
Runs both clang-format and cmake-format.

make fcl
Runs formatting and then cleans build artifacts.

make fc
Runs clang-format and cleans build artifacts.

Cleaning
make clean
Deletes build directory, Doxygen output, and distribution archive to clean the project environment.

Usage Notes
Builds are parallelized automatically using a calculated number of cores, improving build time.

Documentation and packaging targets provide quick workflows to generate project docs and archives.

Testing targets integrate with CTest to run subsets of tests conveniently.

You can format the source and CMake files consistently using provided formatting targets.

Cleaning removes build artifacts and generated files efficiently.

This setup helps automate common development workflows including building, testing, packaging, documentation, and formatting, supporting a smooth developer experience.

