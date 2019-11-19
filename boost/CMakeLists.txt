cmake_minimum_required(VERSION 2.8.3)

project(boost_example)

find_package(Boost 1.55.0 REQUIRED COMPONENTS system coroutine context thread filesystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# to generate a compile_commands.json usable by ycm and other tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    ${Boost_INCLUDE_DIR}
)

## https://codeday.me/bug/20170914/72766.html
# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
# file( GLOB APP_SOURCES RELATIVE app/*.cxx )
file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
message("${APP_SOURCES}")
foreach( testsourcefile ${APP_SOURCES} )
    MESSAGE(${testsourcefile})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${testsourcefile})
    MESSAGE(${FILE_NAME})
    # I used a simple string replace, to cut off .cpp.
    # string( REPLACE ".cpp" "" testname ${testsourcefile} )
    add_executable( ${FILE_NAME} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    target_link_libraries( ${FILE_NAME} ${Boost_LIBRARIES} )
endforeach( testsourcefile ${APP_SOURCES} )
