//
// Created by n.kats on 12.02.2020.
//

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "header.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("error");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr("error");
		return (1);
	}
	line = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{

	}
	close(fd);
}
