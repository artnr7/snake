# 1 правило моих проектов → помечать концы названий пользовательских директорий приставкой _dir 
# 2 перед изменением Мейкфайла запушить изменения в Гитлаб

# FORMAT
include make/cmake_format.mk
include make/clang.mk
include make/clean.mk

include make/format_clean.mk

# PODGOTOVKA
include make/dirs.mk # DIRS
include make/srcs.mk 
include make/exe_files.mk

include make/compilers.mk
# MAIN TARGETS
all: install
include make/install.mk
include make/uninstall.mk

include make/libs.mk
include make/compilation.mk
include make/dvi.mk
include make/dist.mk




include make/play.mk

include make/tests.mk

include make/gcov.mk


include make/cppcheck.mk

include make/gdb.mk
