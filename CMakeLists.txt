cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 14)
project(oj)

# Usage:
# mkdir build && cd build
# cmake -DMAIN:STRING=main/lc11.cpp ..
# make

SET(MAIN "main.cpp" CACHE STRING "Main Source file")

# to generate a compile_commands.json usable by ycm and other tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# string(REGEX REPLACE "/" "_" TARGET ${MAIN})
if(NOT TARGET)
    get_filename_component(TARGET ${MAIN} NAME_WE)
endif()

# The optional <mode> keyword determines the type of message
MESSAGE(STATUS "Target Name: ${TARGET}")

# Bring the headers into the project
# include_directories(lc)
include_directories(.)
# MESSAGE(${CMAKE_CURRENT_SOURCE_DIR})  # 当前处理的CMakeLists.txt所在的路径

# Can manually add the sources using the set command as follows:
#   set(SOURCES lc/bt.cpp lc/list.cpp)
# However, the file(GLOB...) allows for wildcard additions:
#   file(GLOB LC_SRCS "lc/*.cpp")
AUX_SOURCE_DIRECTORY(lc LC_SRCS)
MESSAGE(STATUS "LC_SRCS: " ${LC_SRCS})

add_definitions(-DLOCAL_JUDGE)
# TODO 多个main文件共享lc编译的二进制文件
add_executable(${TARGET} ${MAIN} ${LC_SRCS})
# 清除缓存变量
unset(TARGET CACHE)
