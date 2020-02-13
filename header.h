/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:45:21 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/13 01:29:58 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
#include "get_next_line.h"

typedef struct			s_form //I think, my type is a good idea, kek
{
		int				pos[4][2]; //array of figure
		char			symbol; //name of symbol
		int				x_base; //zero position X coordinate
		int				y_base;//zero position Y coordinate
		struct s_form	*next;
}						t_form;

typedef struct			s_board
{
		char			**map; //array of coordinates
		int				size;
}						t_board;
//place for prototypes of all functions
t_form					*form_new(char **buf, char symbol);
int						beyond_borders(t_form *form, int b_size, int flag);
void					board_free(t_board *board);
t_board					*board_new(int b_size);
void					board_output(t_board *board);
int						board_size(int size);
void					change_symbols(t_board *board, \
										t_form *form, char symbol);
t_form					*form_alignment(t_form *form);
int						form_count(t_form *form);
int						if_overlap(t_board *board, t_form *form);
int						is_it_tetra(char *buf);
void					solution(t_form *form);
int						solve_algorithm(t_board *board, t_form *form);

char					*read_tetramino(int fd, char **line);
int						check_tetramino_line(char **line);

#define MAX_BLOCKS 20
#define MAX_SIMBOLS 5

#endif
