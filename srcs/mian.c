//
// Created by n.kats on 12.02.2020.
//


#include "libft.h"
#include "get_next_line.h"
#include "header.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*file_in_str;
	int		*temp;

	if (argc != 2)
	{
		ft_putstr("error");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY) == -1))
	{
		ft_putstr("error");
		return (1);
	}
	//TODO: malloc temp & file_in_str & free
	temp = (char *)malloc(sizeof(char) * 10);
	file_in_str = (char *)malloc(sizeof(char) * MAX_BLOCKS * (MAX_SIMBOLS + 1));
	if (read_blocks_for_check(file_in_str, temp, argv) != 1)
	{
		free(temp);
		free(file_in_str);
		ft_putstr("error");
		return (-1);
	}
	if (get_tetraminos(fd, argv) == 0)
	{
		ft_putstr("error");
		return (1);
	}


	close(fd);
}

