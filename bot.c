
#include "GNL/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int     main(void)
{
	int     i;
	int     str;
	char    *line;

	str = 0;
	i = open("return.txt", O_RDWR);
	while (++str <= 22 && (get_next_line(0, &line)) > 0)
	{	
		ft_putendl_fd(line, i);
		if (str == 21)
			write(1, "8 2\n", 4);
	}
	str = 0;
	while (++str <= 22 && (get_next_line(0, &line)) > 0)
	{	
		ft_putendl_fd(line, i);
	//	if (str == 21)
	//		write(1, "12 12\n", 4);
	}
	/*str = 0;
	while (++str <= 22 && (get_next_line(0, &line)) > 0)
		ft_putendl_fd(line, i);*/
	return (0);
}
