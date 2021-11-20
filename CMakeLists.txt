cmake_minimum_required(VERSION 3.20)
project(bms)

set(CMAKE_CXX_STANDARD 14)

add_executable(bms main.cpp RSC.cpp RSC.h global.cpp global.h)
