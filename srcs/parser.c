/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:02:53 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/19 01:18:24 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "string.h"

int read_blocks_for_check(char **argv)
{
	int fd;
	int i = 0;
	char *temp;
	char *file_in_str;

	file_in_str = (char *)malloc(sizeof(char) * 26 * 5);
	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (0);
	while (get_next_line(fd, &temp) == 1)
	{
		i++;
		if(i == 5)
		{
			i = 0;
			if(ft_strlen(temp) != 0)
				return (0);
		}
		ft_strcat(file_in_str, temp);
		free(temp);
	}
	if (check_simbols(file_in_str) == -1)
		return (0);
	close(fd);
	free(file_in_str);
	return (1);
}

int check_simbols(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		len--;
		if (str[len] != '#' && str[len] != '.')
		{
			return (-1);
		}
	}
	return (1);
}

char  *get_tetramino(int fd, char *tetraminoshka)
{
	int i;
	char *temp;
	//char file_in_str[256] = {0};

	i = 0;
	ft_strclr(tetraminoshka);
	/*get_next_line(fd, &file_in_str);
	(file_in_str)[4] = 'q';
	(file_in_str)[5] = '\0';*/
	/*if (ft_strlen(temp) == 1 && (temp)[0] == '\0')
		if (get_next_line(fd, &temp) < 0)//for \n like deviders block. I don't know, if last \n get in this "if", we loose
		{
			free (temp);
			return ("error");
		}*/
	while (i < 4) //TODO: check if in file will half tetramino (2 string)
	{
		if(get_next_line(fd, &temp) < 1)
		{
			return ("error");
		}
		temp[4] = 'q';
		temp[5] = '\0';
		ft_strcat(tetraminoshka, temp);
		ft_strclr(temp);
		i++;
		free(temp);
	}
	get_next_line(fd, &temp);
	free (temp);
	return (tetraminoshka);
}

int get_tetraminos_form (char **argv)
{
	char	simbol;
	int 	fd;
	t_form	*head =NULL;
	t_form	*buf = NULL;
	t_form	*buf2 = NULL;

	char *tetraminoshka = (char *)malloc(sizeof(char) * 20);

	simbol = 'A';
	if ((fd = open(argv[1], O_RDONLY) == -1)) //check close(fd) in error
		return (-1);
	char *tempo = get_tetramino(fd, tetraminoshka);
	if (is_it_tetra(tempo) == 0)
		return (-1);
	head = form_new(tempo, simbol);
	buf2 = head;
	while ((tempo = get_tetramino(fd, tetraminoshka)) != "error") //TODO: This is not working becous in after ft_strcat will \0 at the end
	{
		if (tempo[0] == '\0')
			break;
		if (is_it_tetra(tempo) == 0 && tempo)
			return (-1);
		if (tempo)
		{
			buf		   = form_new(tempo, ++simbol);
			buf2->next = buf;
			buf2	   = buf;
		}
	}
	close(fd);

	solution(head);
	form_free(&head);
	//free(tetraminoshka);
	return (1);
}

void form_free(t_form **head)
{
	t_form* prev = NULL;

	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}
