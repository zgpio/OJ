.PHONY: all clean
MKDIR = mkdir
RM = rm
RMFLAGS = -fr
#$(RM) $(RMFLAGS) $(DIRS)

CC = clang++

DIR_EXES = exes
DIRS = $(DIR_EXES)

#EXE = complicated.exe
#EXE := $(addprefix $(DIR_EXES)/, $(EXE))

SRCS = $(wildcard *.cpp)
EXES = $(SRCS:.cpp=.exe)
EXES := $(addprefix $(DIR_EXES)/, $(EXES))
#OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))

ifdef OBJS
EXES = $(addprefix $(DIR_EXES)/, $(OBJS))
all: $(EXES)
endif

#$(warning $(SRCS))
all: $(EXES)

$(DIRS):
	$(MKDIR) $@
# $(EXES): $(SRCS)
# 	$(CC) -o $@ $(filter %.cpp, $^)
$(DIR_EXES)/%.exe: $(DIRS) %.cpp
	$(CC) --target=x86_64-pc-mingw32 -std=c++11 -Wall -g -O0 -o $@ $(filter %.cpp, $^)
clean:
	rd /s/q $(DIR_EXES)

# OPTIONS:
#   --target=<value>        Generate code for the given target
#   -std=<value>            Language standard to compile for
#   -W<warning>             Enable the specified warning, e.g. -Wno-unused
#   -g                      Generate source-level debug information
#   -c                      Only run preprocess, compile, and assemble steps
#   -fexec-charset=gbk
#   -H <file>               Show header includes and nesting depth
# let s:windows_CFlags = 'clang\ --target=x86_64-pc-mingw32\ -Wall\ -g\ -O0\ %\ -o\ '
# let s:linux_CFlags = 'gcc\ -Wall\ -g\ -O0\ %\ -o\ '
# let s:linux_CPPFlags = 'g++\ -Wall\ -g\ -O0\ %\ -o\ '
