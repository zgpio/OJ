.PHONY: all clean
MKDIR = mkdir
RM = rm
RMFLAGS = -fr

CC = clang++

DIR_EXES = exes
DIRS = $(DIR_EXES)

#EXE = complicated.exe
#EXE := $(addprefix $(DIR_EXES)/, $(EXE))

SRCS = $(wildcard *.cpp)
EXES = $(SRCS:.cpp=.exe)
EXES := $(addprefix $(DIR_EXES)/, $(EXES))
#OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))

all: $(EXES)

$(DIRS):
	$(MKDIR) $@
# $(EXES): $(SRCS)
# 	$(CC) -o $@ $(filter %.cpp, $^)
$(DIR_EXES)/%.exe: $(DIRS) %.cpp
	$(CC) --target=x86_64-pc-mingw32 -std=c++11 -Wall -g -O0 -o $@ $(filter %.cpp, $^)

clean:
	$(RM) $(RMFLAGS) $(DIRS)
