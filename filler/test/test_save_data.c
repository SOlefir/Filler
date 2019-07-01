/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_save_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/07/01 17:30:50 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //
#define FD 3

static void		save_size(char *line, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*x = 0;
	*y = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] != ':')
	{
		i++;
		while (line[i] >= '0' && line[i] <= '9')
			*y = (*y * 10) + line[i++] - '0';
		while (line[++i] >= '0' && line[i] <= '9')
			*x = (*x * 10) + line[i] - '0';
	}
}

static void		save_token(char **line, t_f *filler)
{
	int	x;
	int y;

	x = 0;
	y = -1;
	save_size(*line, &filler->token_size_x, &filler->token_size_y);
	free(*line);
	printf("____\n\n");
	printf("size token: {%d %d}\n", filler->token_size_y, filler->token_size_x);
	filler->token = (char**)malloc(sizeof(char*) * filler->token_size_y);
	while (++y < filler->token_size_y && get_next_line(FD, line) > 0)
	{
		x = -1;
		filler->token[y] = (char*)malloc(filler->token_size_x);
		while (++x <= filler->token_size_x)
			filler->token[y][x] = (*line)[x];
		free(*line);
	}
}

static void		save_map(char **line, t_f *filler)
{
	int	i;
	int	j;
	int	s;
	int	len_line;

	save_size(*line, &filler->map_size_x, &filler->map_size_y);
	printf("size map: {%d %d}\n", filler->map_size_y, filler->map_size_x);
	free(*line);
	get_next_line(FD, line);
	free(*line);
	if (filler->map == NULL)
		filler->map = (char**)ft_memalloc(sizeof(char*) * filler->map_size_y);
	len_line = ft_strlen(*line) - filler->map_size_x;
	j = -1;
	while (++j < filler->map_size_y && get_next_line(FD, line) > 0)
	{
		i = -1;
		s = len_line - 1;
		if (filler->map[j] == NULL)
			filler->map[j] = (char*)malloc(filler->map_size_x + 1);
		while (++i <= filler->map_size_x)
			filler->map[j][i] = (*line)[++s];
		printf("%s\n", filler->map[j]);
		free(*line);
	}
}

int				main(void)
{
	char			*line;
	t_f				*filler;

	line = NULL;
	filler = (t_f*)ft_memalloc(sizeof(t_f));
	open("../return.txt", O_RDONLY);
	get_next_line(FD, &line);
	filler->enemy = (line[10] == '1') ? 'X' : 'O';
	free(line);
	printf("enemy: [ %c ]\n\n", filler->enemy);
	printf("____\n\n");
	while (get_next_line(FD, &line) > 0)
	{
		save_map(&line, filler);
		get_next_line(FD, &line);
		save_token(&line, filler);

		int	y = -1;
		printf("\n");
		while (++y < filler->token_size_y)
			printf("%s\n", filler->token[y]);
		printf("____\n");

		make_arr_distance(filler);
		decision(filler);
		ft_masmemdel((void***)&(filler->token), (size_t)filler->token_size_y);
	}
	return (0);
}
