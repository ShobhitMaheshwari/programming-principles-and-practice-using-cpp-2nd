cmake_minimum_required(VERSION 3.2.2)
project(stringpermutation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

#set(SOURCE_FILES src/main.cpp include/Token.h)
file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_executable(stringpermutation ${SOURCES} src/Expression.cpp include/Expression.h include/std_lib_facilities.h src/Token_stream.cpp include/Token_stream.h)
