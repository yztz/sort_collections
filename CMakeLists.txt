cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 99)
project(sort_collections C)

include_directories(.)
aux_source_directory(collections sorters)

add_executable(sort_collections main.c prepare.c global.h utils.c config.h crossline.c crossline.h ${sorters} timer.c timer.h collections/quick_sort.c)
