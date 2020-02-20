# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 05:24:55 by lgunship          #+#    #+#              #
#    Updated: 2020/02/03 02:58:40 by lgunship         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for libft
# Use with 'include /path/to/libft.mk'
# Make sure to define L_FT with path to libft first

L_FT		?= .

FT_NAME		:= libft.a

FT_LNK		:= -L $(L_FT) -l ft
FT_INC		:= -I $(L_FT)/inc
FT_LIB		:= $(L_FT)/$(FT_NAME)

# Global variables for compilation

ifndef LIB_LNK
LIB_LNK		:=
LIB_INC		:=
endif

LIB_LNK		+= $(FT_LNK)
LIB_INC		+= $(FT_INC)
