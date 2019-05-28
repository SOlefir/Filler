/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:59:29 by solefir           #+#    #+#             */
/*   Updated: 2019/05/28 20:03:35 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

static void		make_2d_arr(t_f *filler)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//printf("--> %p\n", filler->distance);
	filler->distance = (int**)malloc(sizeof(int*) * filler->map_size_y);
	//printf("--> %p\n", filler->distance);
	while (++j <= filler->map_size_y)
	{
		filler->distance[j] = (int*)malloc(sizeof(int) * filler->map_size_x);
	//	printf("-> %p\n", filler->distance[j]);
	}
}

static void		find_sit(t_f *filler)
{
	int	x;
	int	y;
	char c;

	x = 0;
	y = 0;
	c = (filler->enemy == 'X') ? 'O' : 'X';
	printf("%c\n", c);
	while (y < filler->map_size_y)
	{
		printf("%c\n", filler->enemy);
		while (x < filler->map_size_x)
		{	
			if (filler->map[y][x] == filler->enemy)
			{
				filler->sit_enemy_y = y;
				filler->sit_enemy_x = x;
			}
			if (filler->map[y][x] == c)
			{
				filler->my_sit_x = x;
				filler->my_sit_y = y;
			}
			if (filler->sit_enemy_y == y && filler->my_sit_y == y)
			{	
				y = filler->map_size_y - 1;
				x = filler->map_size_x - 1;
			}
			x++;
		}
		x = 0;
		y++;
	}

	printf("my\n=| %d - %d |=\n", filler->my_sit_y, filler->my_sit_x);
	printf("%c\n", filler->map[filler->my_sit_y][filler->my_sit_x]);
	printf("enemy\n=| %d - %d |=\n", filler->sit_enemy_y, filler->sit_enemy_x);
	printf("%c\n", filler->map[filler->sit_enemy_x][filler->sit_enemy_x]);
}

void			distance(t_f *filler)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	make_2d_arr(filler);
	find_sit(filler);
}
