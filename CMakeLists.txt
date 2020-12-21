cmake_minimum_required(VERSION 3.17)
project(DictTreePro)

set(CMAKE_C_STANDARD 99)

add_executable(DictTreePro main.c collection/map.h collection/map.c util/util.h util/util.c)