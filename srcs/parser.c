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

int read_blocks_for_check(char *file_in_str, char *temp,char **argv)
{
	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (NULL);
	if ((get_next_line(fd, *file_in_str) != 1) && ft_strlen(file_in_str) != 5 && file_in_str[5] != '\n')
		return (NULL);
	while (get_next_line(fd, *temp) == 1)
	{
		if (ft_strlen(temp) == 1 && temp[0] == '\n')
			if (get_next_line(fd, *temp) != 1)//for \n like deviders block. I don't know, if last \n get in this "if", we loose
				return (NULL);
		if (ft_strlen(temp) != 5 && temp[4] != '\n')
			return (NULL);
		ft_strncat(file_in_str, temp, 4);
	}
	if (check_simbols(file_in_str, temp) == -1)
		return (NULL);
	close(fd);
	return (1);
}

int check_simbols(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] != '#' || str[len] != '.')
		{
			return (-1);
		}
		len--;
	}
}

char *get_tetramino(int fd, char *file_in_str, char *temp;)
{
	int i;

	i = 0;
	get_next_line(fd, *file_in_str);
	if (ft_strlen(temp) == 1 && temp[0] == '\n')
		if (get_next_line(fd, *temp) != 1)//for \n like deviders block. I don't know, if last \n get in this "if", we loose
			return (NULL);
	while (get_next_line(fd, *temp) == 1 && i < 4) //TODO: check if in file will half tetramino (2 string)
	{
		ft_strcat(file_in_str, temp);
		i++;
	}
	return (file_in_str);
}

void get_tetraminos (int fd, char *file_in_str, char *temp)
{
	char	simbol;
	t_form	*head;
	t_form	*buf;
	t_form	buf2;

	simbol = 'A';
	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (NULL);
	head = form_new(get_tetramino(fd, file_in_str, temp), simbol);
	buf2 = head;
	while (file_in_str[6] != '\0') //TODO: This is not working becous in after ft_strcat will \0 at the end
	{
		buf = form_new(get_tetramino(fd, file_in_str, temp), ++simbol);
		buf2->next = buf;
		buf2 = buf;
	}
}