
#include "GNL/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int     main(void)
{
	int     i;
	int     str;
	char    *line;

	str = 22;
	i = open("return.txt", O_RDWR);
	write(1, "2 8\n", 4);
	while (--str >= 0 && (get_next_line(0, &line)) > 0)
	{    
		ft_putendl_fd(line, i);
		write(1, "2 8\n", 4);
	}
	while (--str >= 0 && (get_next_line(0, &line)) > 0)
	{
		ft_putendl_fd(line, i);
		write(1, "2 8\n", 4);
	}
	return (0);
}
