cmake_minimum_required(VERSION 3.24)
project(K_D_Tree)

set(CMAKE_CXX_STANDARD 11)

add_executable(K_D_Tree src/main.cpp src/KDTree.cpp src/point_generation.cpp)
add_executable(K_D_Tree_Correctesa src/main_correctesa.cpp src/KDTree.cpp src/point_generation.cpp)
