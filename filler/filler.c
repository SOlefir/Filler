/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:40:27 by solefir           #+#    #+#             */
/*   Updated: 2019/06/21 20:30:45 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

static char		*do_step(t_f *filler, int y, int x) // дописать
{
	char	*str;
	int		len_y;
	int		len_x;
	int		nbr

	len = 0;
	nbr = y;
	while ((nbr = nbr / 10) > 0)
		len_y++;
	nbr = x;
	while ((nbr = nbr / 10) > 0)
		len_x++;
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	while ((--len_y >= 0) || ((len_y <= 0) && (--len_x >= 0)))
	{
		str[len] = nbr < 0 ? 32 : '0' + (nbr % 10);
		 = nbr / 10;
	}
	
	return (*str);
}
static _Bool    crossing_border(t_f *filler, int y, int x)
{
	int     j;
	int     i;

	j = -1;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
			if (filler->token[j][i] == '*' &&
				(y + j) > filler->map_size_y && (x + i) > filler->map_size_x)
				return (1);
	}
	return (0);
}


static _Bool    crossing_enemy_char(t_f *filler, int y, int x)
{
	int     j;
	int     i;
	
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

static int    crossing_my_char(t_f *filler, int y, int x)
{
	int     j;
	int     i;
	int		crossing;
	char    my_char;

	crossing = 0;
	my_char = (filler->enemy == 'X') ? 'O' : 'X';
	j = -1;
	//printf(" | y = %d x = %d |\n ", y, x);
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
		{
			if (filler->token[j][i] == '*' &&
				(filler->map[y + j][x + i] == my_char ||
				filler->map[y + j][x + i] == (my_char + 32)))
				crossing++;
			/*if (y < 7)
				printf("// %c //\n", filler->map[y + j][x + i]);*/
		}
	}
//	printf("{ %d }\n", crossing);
	return (crossing);
}

void		decision(t_f *filler)
{
	int y;
	int x;
	int step;
	int	min_distance;

	step = min_distance_sum(filler, 0, 0);
	y = -1;
	while (++y < filler->map_size_y &&
	filler->map_size_y >= (filler->token_size_y + y))
	{
		x = -1;
		while (++x < filler->map_size_x &&
		filler->map_size_x >= (filler->token_size_x + x))
		{
			min_distance = min_distance_sum(filler, y, x);
			if (!crossing_border(filler, y, x) &&
				crossing_my_char(filler, y, x) == 1 &&
				!crossing_enemy_char(filler, y, x))
			{
				step = min_distance < step ? min_distance : step;
				filler->my_step = do_step(filler, y, x);
				printf(RED "%c", filler->map[y][x]);
			}
			else
				printf(RESET "%c", filler->map[y][x]);
		}
		printf("\n");
	}
}
