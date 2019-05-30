/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:59:29 by solefir           #+#    #+#             */
/*   Updated: 2019/05/30 20:47:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

static void		make_2d_arr(t_f *filler)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	filler->distance = (int**)malloc(sizeof(int*) * filler->map_size_y);
	while (++j < filler->map_size_y)
		filler->distance[j] = (int*)ft_memalloc(sizeof(int) * filler->map_size_x);
}

static void		enemy_is_one(t_f *filler)
{
	int	y;
	int	x;

	y = -1;
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			if (filler->map[y][x] == filler->enemy ||
				filler->map[y][x] == (filler->enemy - 32))
			{	
				filler->distance[y][x] = 1;
			}
			printf("%d", filler->distance[y][x]);
		}
		printf("\n");
	}
}

static void		calculate_distance(t_f *filler, int y, int x)
{
	int	i;
	int	j;
	int min;

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			min = ((x - i) + (y - j));
			if (filler->distance[j][i] == 0)
				filler->distance[j][i] = min;
			else
				filler->distance[j][i] = (min <= filler->distance[j][i]) 
										? min : filler->distance[j][i];
			//printf("%d", filler->distance[j][i]);
		}
	}
}

void			distance(t_f *filler)
{
	int	x;
	int	y;

	y = -1;
	make_2d_arr(filler);
	enemy_is_one(filler);
	printf("\n");
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			if (filler->distance[y][x] == 1)
				calculate_distance(filler, y, x);
		}
	}
	y = -1;
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			//printf("{%d | %d}\n", y, x);
			printf("%d ", filler->distance[y][x]);
		}
		printf("\n");
	}
}
