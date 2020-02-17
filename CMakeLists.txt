# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.10)
project(fillit C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(srcs)
include_directories(libft)

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
        srcs/parser.c
        srcs/get_next_line.c
        header.h srcs/mian.c
        libft/ft_strnew.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_strlen.c
        libft/ft_strcat.c
        libft/ft_strncat.c
        libft/ft_strjoin.c
        libft/ft_strchr.c
        libft/ft_strsub.c
        libft/ft_strdup.c
        libft/ft_strdel.c
        libft/ft_memalloc.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_bzero.c
        libft/ft_strclr.c
        get_next_line.h)
