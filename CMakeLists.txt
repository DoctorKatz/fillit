# cmake_minimum_required(VERSION <specify CMake version here>)
project(fillit C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(srcs)

add_executable(fillit
        srcs/beyond_borders.c
        srcs/board_free.c
        srcs/board_new.c
        srcs/board_output.c
        srcs/board_size.c
        srcs/change_symbols.c
        srcs/form_alignment.c
        srcs/form_count.c
        srcs/form_new.c
        srcs/if_overlap.c
        srcs/is_it_tetra.c
        srcs/solution.c
        srcs/solve_algorithm.c
        header.h srcs/mian.c)
