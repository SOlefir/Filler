/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/06/29 18:41:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define FD 0

static void		save_size(char *line, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	y = 0;
	filler->token_size_x = 0;
	filler->token_size_y = 0;
	save_size(*line, &filler->token_size_x, &filler->token_size_y);
	free(*line);


	filler->token = (char**)malloc(sizeof(char*) * filler->token_size_y);
	while (y < filler->token_size_y && get_next_line(FD, line) > 0)
	{
		filler->token[y] = (char*)malloc(filler->token_size_x);
		while (x < filler->token_size_x)
		{
			filler->token[y][x] = (*line)[x];
			x++;
		}
		filler->token[y][x] = '\0';
		free(*line);
		y++;
		x = 0;
	}
}

static void		save_map(char *line, t_f *filler, int j)
{
	int	i;
	int	s;

	s = ft_strlen(line);
	i = 0;
	filler->map[j] = (char*)malloc(filler->map_size_x + 1);
	s = s - filler->map_size_x;
	while (i <= filler->map_size_x)
	{
		filler->map[j][i] = line[s];
		s++;
		i++;
	}
}

static t_f		*make_struct(t_f *filler, char **line)
{
	filler = (t_f*)ft_memalloc(sizeof(t_f));
	if ((*line)[0] == '$')
	{
		filler->enemy = ((*line)[10] == '1') ? 'X' : 'O';
		free(*line);
		get_next_line(FD, line);
	}
	save_size(*line, &filler->map_size_x, &filler->map_size_y);
	free(*line);
	filler->map = (char**)ft_memalloc(sizeof(char*) * filler->map_size_y);
	return (filler);
}

int				main(void)
{
	char			*line;
	int				j;
	t_f				*filler;

	line = NULL;
//	open("return.txt", O_RDONLY);//
	get_next_line(FD, &line);
	filler = NULL;
	filler = make_struct(filler, &line);
	j = -1;
	while (get_next_line(FD, &line) > 0)
	{
		if (j != -1) {
			get_next_line(FD, &line);
		}
		j = -1;
		while (++j != filler->map_size_y)
		{
			get_next_line(FD, &line);
			save_map(line, filler, j);
		}
		get_next_line(FD, &line);			
		save_token(&line, filler);
		make_arr_distance(filler);
		decision(filler);
	}
	return (0);
}
