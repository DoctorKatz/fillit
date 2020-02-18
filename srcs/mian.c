//
// Created by n.kats on 12.02.2020.
//

#include "get_next_line.h"
#include "header.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
	int		fd;

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
	close(fd);
	if (read_blocks_for_check(argv) != 1)
	{
		ft_putstr("error1");
		return (-1);
	}
	if (get_tetraminos_form(argv) != 1)
	{
		ft_putstr("error2");
		return (-1);
	}
	return (1);
}

