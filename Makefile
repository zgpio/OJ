.PHONY: all clean
MKDIR = mkdir
RM = rm
RMFLAGS = -fr
#$(RM) $(RMFLAGS) $(DIRS)

CC = clang++

# ref to https://gist.github.com/sighingnow/deee806603ec9274fd47
OSFLAG :=
ifeq ($(OS),Windows_NT)
	OSFLAG += --target=x86_64-pc-mingw32
endif

EXE_DIR = exes
DIRS = $(EXE_DIR)

SRCS = $(wildcard *.cpp)
EXES = $(SRCS:.cpp=.exe)
EXES := $(addprefix $(EXE_DIR)/, $(EXES))

ifdef OBJS
EXES = $(addprefix $(EXE_DIR)/, $(OBJS))
all: $(EXES)
endif

#$(warning $(SRCS))
all: $(EXES)

$(DIRS):
	$(MKDIR) $@
# $(EXES): $(SRCS)
# 	$(CC) -o $@ $(filter %.cpp, $^)
# for Windows
$(EXE_DIR)/%.exe: $(DIRS) %.cpp
	$(CC) --target=x86_64-pc-mingw32 -std=c++11 -Wall -g -O0 -o $@ $(filter %.cpp, $^)
# for Linux
$(EXE_DIR)/%: $(DIRS) %.cpp
	$(CC) -std=c++11 -Wall -g -O0 -o $@ $(filter %.cpp, $^) $(wildcard lc/*.cpp)
clean:
	rd /s/q $(EXE_DIR)

# OPTIONS:
#   --target=<value>        Generate code for the given target
#   -std=<value>            Language standard to compile for
#   -W<warning>             Enable the specified warning, e.g. -Wno-unused
#   -g                      Generate source-level debug information
#   -c                      Only run preprocess, compile, and assemble steps
#   -fexec-charset=gbk
#   -H <file>               Show header includes and nesting depth
