cmake_minimum_required(VERSION 3.16)
project(Hotel-Management-System)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB_RECURSE DIR_SRC "./src/*.cpp")
add_executable(Hotel-Management-System ${DIR_SRC})