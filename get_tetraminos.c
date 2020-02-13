#include "header.h"

char *read_tetramino (int fd, char **line)
{
	char	*tetramino_bit;
	char	tetramino;
	int		i;
	int		ret;


	i = 0;
	tetramino_bit = (char *) malloc(sizeof(char) * 21);
	tetramino  = tetramino_bit;
	while (i < 4)
	{
		if (get_next_line(fd, &line) != 1)
			break;
		if (check_tetramino_line(&line) == -1)
			return (NULL);
		tetramino_bit = *line;
		tetramino_bit += sizeof(char) * 5;
		i++;
	}
	if (get_next_line(fd, &line) != 1)
		return (NULL);
	if (is_it_tetra(tetramino) != 1)
		return (NULL);
	return (tetramino);
}

int check_tetramino_line(char **line)
{
	int	i;

	i = 0;
	if (ft_strlen(*line) != 5)
		return (-1);
	while (i < 3)
	{
		if (line[i] != '#' && line[i] != '.')
		{
			ft_putstr("error");
			return (-1);
		}
		i++;
	}
	if (line[5] == '\n')
		return (-1);
}

void get_tetraminos (int fd, char **line)
{
	char	simbol;
	t_form	*head;
	t_form	*buf;
	t_form	buf2;

	simbol = 'A';
	if (get_tetramino(fd, line) == NULL)
		return (NULL);
	head = form_new(tetramino, simbol);
	buf2 = head;
	while (1)
	{
		buf = form_new(read_tetramino());
		buf2->next = buf;
		buf2 = buf;
		if (get_tetramino(fd, line) == NULL)
			break;
	}
}