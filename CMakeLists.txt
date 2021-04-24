cmake_minimum_required(VERSION 3.17)
project(Hotel-Management-System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hotel-Management-System main.cpp Dish/Dishes.cpp Dish/Dishes.h Dish/DishInfo.cpp Dish/DishInfo.h)