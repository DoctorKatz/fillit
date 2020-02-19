NAME	:= fillit

# directories
SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft

# src / obj files
SRC		:= srcs/beyond_borders \
                 srcs/board_free \
                 srcs/board_new \
                 srcs/board_output \
                 srcs/board_size. \
                 srcs/change_symbols.c \
                 srcs/form_alignment.c \
                 srcs/form_count.c \
                 srcs/form_new.c \
                 srcs/if_overlap.c \
                 srcs/is_it_tetra.c \
                 srcs/solution.c \
                 srcs/solve_algorithm.c \
                 srcs/parser.c \
                 srcs/get_next_line.c \
                 srcs/read_and_check.c \
                 srcs/form_free.c \
                 srcs/mian.c \
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

# libraries
L_FT	:= $(LIB_DIR)/

#include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) re --no-print-directory
