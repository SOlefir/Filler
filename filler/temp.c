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


static void		enemy_is_one(t_f *filler)
{
	int	y;
	int	x;
	int i;

	i = 0;
	y = -1;
	printf("   0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|\n");
	printf("   ----------------------------------\n");
	while (++y < filler->map_size_y)
	{
		x = -1;
		i <= 9 ? printf(" %d|", i) : printf("%d|", i);
		i++;
		while (++x < filler->map_size_x)
		{
			if (filler->map[y][x] == filler->enemy ||
				filler->map[y][x] == (filler->enemy + 32))
			{	
				filler->distance[y][x] = 1;
			}
			printf("%d|", filler->distance[y][x]);
		}
		printf("\n");
	}
}

tatic void		save_step(t_f *filler, int y, int x) // дописать
{
	int		len_y;
	int		len_x;
	int		nbr;

	len_y = 1;
	len_x = 1;
	nbr = y;
	//printf(" y = %d | x = %d \n", y, x);
	if (filler->my_step != NULL)
		free(filler->my_step);
	while ((nbr = nbr / 10) > 0)
		len_y++;
	//printf(" len_y = %d \n", len_y);
	nbr = x;
	while ((nbr = nbr / 10) > 0)
		len_x++;
	len_x++;
	//printf(" len_x = %d \n", len_x);
	filler->my_step = (char *)malloc(len_y + len_x);
	filler->my_step[len_y + len_x] = '\0';
	while ((--len_y >= 0) || ((len_y <= 0) && (--len_x >= 0)))
	{
		filler->my_step[len_y + len_x] = y < 0 ? ' ' : (nbr % 10) + '0';
		nbr = y > 0 ? y / 10 : x / 10;
	}
	//printf("{ %s }\n", filler->my_step);
}


   0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|
   ----------------------------------
 0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 1|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 2|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 3|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 4|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 5|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 6|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 7|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 8|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
 9|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
10|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
11|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|0|0|
12|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
13|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
14|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|


функция, где я буду сохранять оптимальную позицию. возможно стоит переписать фнкц решение.
чтобы проверять не только пересечение, но и оптимальность позиции. фозможно стоит прописать еще один файл с проверкой
оптимальности. 


    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
   ----------------------------------------------------
 0| 22 21 20 19 18 17 16 15 14 13 12 11 10 11 12 13 14
 1| 21 20 19 18 17 16 15 14 13 12 11 10  9 10 11 12 13
 2| 20 19 18 17 16 15 14 13 12 11 10  9  8  9 10 11 12
 3| 19 18 17 16 15 14 13 12 11 10  9  8  7  8  9 10 11
 4| 18 17 16 15 14 13 12 11 10  9  8  7  6  7  8  9 10
 5| 17 16 15 14 13 12 11 10  9  8  7  6  5  6  7  8  9
 6| 16 15 14 13 12 11 10  9  8  7  6  5  4  5  6  7  8
 7| 15 14 13 12 11 10  9  8  7  6  5  4  3  4  5  6  7
 8| 14 13 12 11 10  9  8  7  6  5  4  3  2  3  4  5  6
 9| 13 12 11 10  9  8  7  6  5  4  3  2  1  2  3  4  5
10| 12 11 10  9  8  7  6  5  4  3  2  1  0  1  2  3  4
11| 13 12 11 10  9  8  7  6  5  4  3  2  1  2  3  4  5
12| 14 13 12 11 10  9  8  7  6  5  4  3  2  3  4  5  6
13| 15 14 13 12 11 10  9  8  7  6  5  4  3  4  5  6  7
14| 16 15 14 13 12 11 10  9  8  7  6  5  4  5  6  7  8

token_size = filler->token_size_x > filler->token_size_y ?
				filler->token_size_x : filler->token_size_y;