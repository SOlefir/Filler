/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:59:29 by solefir           #+#    #+#             */
/*   Updated: 2019/07/04 11:14:12 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		make_2d_arr(t_f *filler)
{
	int	j;

	j = -1;
	filler->distance = (int**)malloc(sizeof(int*) * filler->map_size_y);
	while (++j < filler->map_size_y)
		filler->distance[j] =
						(int*)ft_memalloc(sizeof(int) * filler->map_size_x);
}

static void		calculate_distance(t_f *filler, int y, int x)
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
			min = ABS(x - i) + ABS(y - j);
			if (filler->distance[j][i] == 0 &&
			(filler->map[j][i] != filler->enemy &&
			filler->map[j][i] != (filler->enemy + 32)))
			{
				min = x > (filler->map_size_x / 2)
					? ABS(min - 1) : min;
				filler->distance[j][i] = y < (filler->map_size_y / 2)
										? ABS(min - 2) : min;
			}
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
	if (filler->distance == NULL)
		make_2d_arr(filler);
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			if (filler->map[y][x] == filler->enemy ||
				filler->map[y][x] == filler->enemy + 32)
				calculate_distance(filler, y, x);
		}
	}
}
