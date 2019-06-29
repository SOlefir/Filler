/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chek_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:55:38 by solefir           #+#    #+#             */
/*   Updated: 2019/06/29 17:23:56 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"
#include <stdio.h> //

static	_Bool	is_mediana(t_f *filler, int y)
{
	int	madiane;

	madiane = filler->map_size_y;
	if (y <= (madiane + 4) && y >= madiane)
		return (1);
	return (0);
}

static	void	min_distance_sum(t_f *filler, int y, int x)
{
	int	i;
	int j;
	int	sum;

	j = -1;
	sum = 0;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
			if (filler->token[j][i] == '*')
				sum += filler->distance[y + j][x + i];
	}
	filler->min_distance_sum = filler->min_distance_sum == 0 ? sum :
								filler->min_distance_sum;
	if (sum <= filler->min_distance_sum)
	{
		filler->min_distance_sum = sum;
		filler->my_step_x = x;
		filler->my_step_y = y;
	}
}

void				chek_step(t_f *filler, int y, int x)
{
	int	i;
	int j;

	j = y - 1;
	while (++j < filler->map_size_y)
	{
		i = x - 1;
		while (++i < filler->map_size_x)
		{
			if (filler->map[j][i] == filler->enemy &&
				(is_mediana(filler, j) || ABS(y - j) >= 4))
			{
				filler->my_step_x = x;
				filler->my_step_y = y;
			}
			else
				min_distance_sum(filler, y, x);
		}
	}
}

/* 
		1. проверить свою позицию на карте. стремиться заполнить большую часть карты.
		2. где находится враг, если он прорвался на мою сторону, то необходимо ему срезать путь
		3. расстояние между мной и врагом. если большое, то можно двигаться по направлению к врагу и на полпути начинать окружать
*/