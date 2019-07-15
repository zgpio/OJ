cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 14)
project(directory_test)

SET(FAB "po" CACHE STRING "Some user-specified option")
#Bring the headers, such as Student.h into the project
include_directories(lc)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#  TODO: 尚未完成
file(GLOB SOURCES "lc/*.cpp")
file(GLOB SOURCES ${FAB})

add_executable(${FAB} ${SOURCES})
