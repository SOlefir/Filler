/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:40:27 by solefir           #+#    #+#             */
/*   Updated: 2019/07/03 19:22:03 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void		min_distance_sum(t_f *filler, int y, int x)
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
	if (filler->min_distance_sum == 0)
		filler->min_distance_sum = sum;
	if (sum <= filler->min_distance_sum)
	{
		filler->min_distance_sum = sum;
		filler->my_step_x = x;
		filler->my_step_y = y;
	}
}

static _Bool		crossing_border(t_f *filler, int y, int x)
{
	int	j;
	int	i;

	j = -1;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
			if (filler->token[j][i] == '*' &&
				((i + x) >= filler->map_size_x ||
				(j + y) >= filler->map_size_y))
				return (1);
	}
	return (0);
}

static _Bool		crossing_enemy_char(t_f *filler, int y, int x)
{
	int	j;
	int	i;

	j = -1;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
			if (filler->token[j][i] == '*' &&
				(filler->map[y + j][x + i] == filler->enemy ||
				filler->map[y + j][x + i] == (filler->enemy + 32)))
				return (1);
	}
	return (0);
}

static int			crossing_my_char(t_f *filler, int y, int x)
{
	int		j;
	int		i;
	int		crossing;
	char	my_char;

	crossing = 0;
	my_char = (filler->enemy == 'X') ? 'O' : 'X';
	j = -1;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
		{
			if (filler->token[j][i] == '*' &&
				(filler->map[y + j][x + i] == my_char ||
				filler->map[y + j][x + i] == (my_char + 32)))
				crossing++;
		}
	}
	return (crossing);
}

void				decision(t_f *filler)
{
	int	y;
	int	x;

	y = -1;
	filler->min_distance_sum = 0;
	while (++y < filler->map_size_y)
	{
		x = -1;
		while (++x < filler->map_size_x)
		{
			if (!crossing_border(filler, y, x) &&
				crossing_my_char(filler, y, x) == 1 &&
				!crossing_enemy_char(filler, y, x))
			{
				min_distance_sum(filler, y, x);
			}
		}
	}
	ft_putnbr(filler->my_step_y);
	ft_putchar(' ');
	ft_putnbr(filler->my_step_x);
	ft_putchar('\n');
}
