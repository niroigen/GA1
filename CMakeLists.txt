cmake_minimum_required(VERSION 3.15)
project(GA1)

set(CMAKE_CXX_STANDARD 14)

link_libraries(GA1 ea.h helper.h individual.h)
add_executable(GA1 main.cpp ea.cpp individual.cpp helper.cpp)