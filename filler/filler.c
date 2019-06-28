/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:40:27 by solefir           #+#    #+#             */
/*   Updated: 2019/06/28 19:12:19 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"


static _Bool    crossing_border(t_f *filler, int y, int x) //нужно доработать, чтобы пересечением границы было только если '*'
{
	int     j;
	int     i;

	j = -1;
	while (++j < filler->token_size_y)
	{
		i = -1;
		while (++i < filler->token_size_x)
			if (filler->token[j][i] == '*' &&
				(filler->map[y][i + x] == '\n' ||
				filler->map[j + y] == NULL))
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
	//printf("-> %c <- \n", filler->enemy);
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
	
	y = -1;
	//printf("map{y = %d | x = %d}\n", filler->map_size_y, filler->map_size_x);
	//printf("tok{y = %d | x = %d}\n", filler->token_size_y, filler->token_size_x);
	while (++y < filler->map_size_y &&
			filler->map_size_y >= (filler->token_size_y + y))
	{
		x = -1;
		while (++x < filler->map_size_x &&
		filler->map_size_x >= (filler->token_size_x + x))
		{
			if (!crossing_border(filler, y, x) &&
				crossing_my_char(filler, y, x) == 1 &&
				!crossing_enemy_char(filler, y, x))
			{
				printf(RED "%c", filler->map[y][x]);
				chek_step(filler, y, x);
			}
			else
				printf(RESET "%c", filler->map[y][x]);
		}
		printf("\n");
	}
	//printf("[ y = %d | x = %d ]\n", filler->my_step_y, filler->my_step_x);
//	printf("\n");
	//print_map_and_step(filler);
//	printf("\n");
	ft_putnbr(filler->my_step_y);
	ft_putchar(' ');
	ft_putnbr(filler->my_step_x);
	ft_putchar('\n');

}
