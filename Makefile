NAME	:=	fillit

# directories
SRC_DIR	:=	./srcs
INC_DIR	:=	./inc
OBJ_DIR	:=	./obj
LIB_DIR	:=	./libft

# src / obj files
SRC	:=	beyond_borders.c \
	/board_free.c \
	/board_new.c \
	/board_output.c \
	/board_size.c \
	/change_symbols.c \
	/form_alignment.c \
	/form_count.c \
	/form_new.c \
	/if_overlap.c \
	/is_it_tetra.c \
	/solution.c \
	/solve_algorithm.c \
	/parser.c \
	/get_next_line.c \
	/read_and_check.c \
	/form_free.c \
	/main.c

OBJ	:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC:=	gcc
CFLAGS:=	-Wall -Wextra -Werror -pedantic -std=c99
OFLAGS:=	-pipe -flto
CFLAGS+=	$(OFLAGS)

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
