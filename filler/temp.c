/* find far sit for 'O' && find closer sit for 'X'
 НУЖНО ПЕРЕДЕЛАТЬ! Искать точки и потом сравнивать их, чтобы запоминать только те, что имеют между собой наименьший разрыв
 2 цикла: для х и для о, сохранять в переменную и сравнивать их между собой в этом цикле*/

static void		find_sit(t_f *filler)
{
	int		x;
	int		y;
	int		first;

	x = 0;
	y = 0;
	first = 0;
	while (y < filler->map_size_y)
	{
		printf("%c\n", filler->enemy);
		while (x < filler->map_size_x)
		{	
			printf("%c\n", filler->map[y][x]);
			if (filler->map[y][x] == 'O' || filler->map[y][x] == 'o')
			{
				if (filler->enemy == 'O')
				{
					filler->sit_enemy_y = y;	
					filler->sit_enemy_x = x;
				}
				else
				{
					filler->my_sit_x = x;
					filler->my_sit_y = y;
				}
			}
			if (filler->map[y][x] == 'X' || filler->map[y][x] == 'x')
			{
				if (filler->enemy == 'X')
				{
					filler->sit_enemy_y = y;	
					filler->sit_enemy_x = x;
				}
				else
				{
					filler->my_sit_x = x;
					filler->my_sit_y = y;
				}
			}
			if (filler->sit_enemy_x > 0 && filler->my_sit_x > 0)
			{
				first = (filler->my_sit_x - filler->sit_enemy_x) +
						(filler->my_sit_y - filler->sit_enemy_y);
				first *= (first < 0) ? -1 : 1; // сделать булевую фнкц котора будет сравнивать

			}
			x++;
		}
		y++;
		x = 0;
	}
	printf("my\n=| %d - %d |=\n", filler->my_sit_y, filler->my_sit_x);
	printf("%c\n", filler->map[filler->my_sit_y][filler->my_sit_x]);
	printf("enemy\n=| %d - %d |=\n", filler->sit_enemy_y, filler->sit_enemy_x);
	printf("%c\n", filler->map[filler->sit_enemy_y][filler->sit_enemy_x]);
}
/* find far sit for 'O' && find closer sit for 'X'
 НУЖНО ПЕРЕДЕЛАТЬ! Искать точки и потом сравнивать их, чтобы запоминать только те, что имеют между собой наименьший разрыв
 2 цикла: для х и для о, сохранять в переменную и сравнивать их между собой в этом цикле*/

static void		find_sit(t_f *filler)
{
	int		x;
	int		y;
	int		first;

	x = 0;
	y = 0;
	first = 0;
	while (y < filler->map_size_y)
	{
		printf("%c\n", filler->enemy);
		while (x < filler->map_size_x)
		{	
			printf("%c\n", filler->map[y][x]);
			if (filler->map[y][x] == 'O' || filler->map[y][x] == 'o')
			{
				if (filler->enemy == 'O')
				{
					filler->sit_enemy_y = y;	
					filler->sit_enemy_x = x;
				}
				else
				{
					filler->my_sit_x = x;
					filler->my_sit_y = y;
				}
			}
			if (filler->map[y][x] == 'X' || filler->map[y][x] == 'x')
			{
				if (filler->enemy == 'X')
				{
					filler->sit_enemy_y = y;	
					filler->sit_enemy_x = x;
				}
				else
				{
					filler->my_sit_x = x;
					filler->my_sit_y = y;
				}
			}
			if (filler->sit_enemy_x > 0 && filler->my_sit_x > 0)
			{
				first = (filler->my_sit_x - filler->sit_enemy_x) +
						(filler->my_sit_y - filler->sit_enemy_y);
				first *= (first < 0) ? -1 : 1; // сделать булевую фнкц котора будет сравнивать

			}
			x++;
		}
		y++;
		x = 0;
	}
	printf("my\n=| %d - %d |=\n", filler->my_sit_y, filler->my_sit_x);
	printf("%c\n", filler->map[filler->my_sit_y][filler->my_sit_x]);
	printf("enemy\n=| %d - %d |=\n", filler->sit_enemy_y, filler->sit_enemy_x);
	printf("%c\n", filler->map[filler->sit_enemy_y][filler->sit_enemy_x]);
}
