/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:02:53 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/13 01:29:58 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "string.h"

int read_blocks_for_check(char *file_in_str, char *temp, char **argv)
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (0);
	//if ((get_next_line(fd, &file_in_str) != 1) && ft_strlen(file_in_str) != 5 && file_in_str[5] != '\n')
		//return (0);
	while (get_next_line(fd, &temp) == 1)
	{
		if (ft_strlen(temp) == 1 && temp[0] == '\0')
			if (get_next_line(fd, &temp) != 1)//for \n like deviders block. I don't know, if last \n get in this "if", we loose
				return (0);
		if ((ft_strlen(temp) != 4 && temp[4] != '\n') && ((temp[0] != '\0')))
			return (0);
		ft_strncat(file_in_str, temp, 4);
	}
	if (check_simbols(file_in_str) == -1)
		return (0);
	close(fd);
	return (1);
}

int check_simbols(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] != '#' && str[len] != '.' && str[ft_strlen(str)])
		{
			return (-1);
		}
		len--;
	}
}

char  *get_tetramino(int fd, char *file_in_str, char *temp)
{
	int i;

	i = 0;
	ft_strclr(file_in_str);
	get_next_line(fd, &file_in_str);
	file_in_str[4] = 'q';
	file_in_str[5] = '\0';
	if (ft_strlen(temp) == 1 && temp[0] == '\0')
		if (get_next_line(fd, &temp) != 1)//for \n like deviders block. I don't know, if last \n get in this "if", we loose
			return ("error");
	while (i < 4) //TODO: check if in file will half tetramino (2 string)
	{
		if(get_next_line(fd, &temp) != 1)
			return ("error");
		temp[4] = 'q';
		temp[5] = '\0';
		ft_strcat(file_in_str, temp);
		i++;
	}
	return (file_in_str);
}

int get_tetraminos_form (char *file_in_str, char *temp, char **argv)
{
	char	simbol;
	int 	fd;
	t_form	*head;
	t_form	*buf;
	t_form	*buf2;

	simbol = 'A';
	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (-1);
	char *tempo = get_tetramino(fd, file_in_str, temp);
	if (is_it_tetra(tempo) != 0)
		return (-1);
	head = form_new(tempo, simbol);
	buf2 = head;
	while ((tempo = get_tetramino(fd, file_in_str, temp)) != "error") //TODO: This is not working becous in after ft_strcat will \0 at the end
	{
		if (is_it_tetra(tempo) != 0)
			return (-1);
		buf = form_new(tempo, ++simbol);
		buf2->next = buf;
		buf2 = buf;
	}
	close(fd);
	solution(head);
	return (1);
}