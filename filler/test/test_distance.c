/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:59:29 by solefir           #+#    #+#             */
/*   Updated: 2019/06/30 17:50:03 by solefir          ###   ########.fr       */
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

static void		calculate_distance(t_f *filler, int y, int x) // добавить проверку на то в какой части карты я и враг. и увеличить вес этих ячеек
{
	int	i;
	int	j;
	int min;

	j = -1;
	while (++j < filler->map_size_y)
	{
		i = -1;
		while (++i < filler->map_size_x)
		{
			min = ABS(x - i) + ABS(y - j); // здесь проверку. ? mediane_map : min - 1
			if (filler->distance[j][i] == 0 && 
			(filler->map[j][i] != filler->enemy && filler->map[j][i] != (filler->enemy + 32)))
				filler->distance[j][i] = min;
			else
				filler->distance[j][i] = (min < filler->distance[j][i]) 
										? min : filler->distance[j][i];
		}
	}
}

void			make_arr_distance(t_f *filler)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = 0;
	make_2d_arr(filler);
	printf("\n");
	printf("     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16\n");
	printf("   ----------------------------------------------------\n");
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			if (filler->map[y][x] == filler->enemy || filler->map[y][x] == filler->enemy + 32)
				calculate_distance(filler, y, x);
		}
	}
	
	y = -1;
	while (++y < filler->map_size_y)
	{
		i <= 9 ? printf(" %d|", i) : printf("%d|", i);
		i++;
		x = -1;
		while (++x < filler->map_size_x)
		{
			//printf("{%d | %d}\n", y, x);
			filler->distance[y][x] > 9 ? printf(" %d", filler->distance[y][x])
										: printf("  %d", filler->distance[y][x]);
		}
		printf("\n");
	}
}
