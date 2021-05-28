cmake_minimum_required(VERSION 3.15)
project(Hotel-Management-System)

set(CMAKE_CXX_STANDARD 14)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
add_executable(Hotel-Management-System ${DIR_SRCS})