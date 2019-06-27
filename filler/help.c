
#include "filler.h"
#include <stdio.h> //

void		print_map_and_step(t_f *filler)
{
	int     y;
	int     x;
	int		i;
	int		j;
	int		step_x;
	int		step_y;

	step_x = filler->my_step_x;
	step_y = filler->my_step_y;
	y = -1;
	j = 0;
	while (y < filler->map_size_y )
	{
		y++;
		x = 0;
		while (x < filler->map_size_x)
		{	
			if (y == step_y && x == step_x)
			{
				while (j < filler->token_size_y || y < filler->map_size_y)
				{
					i = 0;
					while (i < filler->token_size_x || x < filler->map_size_x)
					{
						if (filler->token[j + y][i + x] == '*')
							printf("O");
						else
							printf("%c", filler->map[y][x]);
						x++;
						i++;
					}
					y++;
					j++;
					printf("\n");
				}
			}
			else
				printf("%c", filler->map[y][x++]);
		}
		printf("\n");
	}
}
