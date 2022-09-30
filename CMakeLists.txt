cmake_minimum_required(VERSION 3.22)
project(sort_collections C)

set(CMAKE_C_STANDARD 99)

add_executable(sort_collections main.c prepare.c global.h bubble.c)
