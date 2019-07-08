/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/07/03 19:33:30 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	ft_strdel(&line);
}

void			save_token(char **line, t_f *filler)
{
	int	x;
	int y;

	y = -1;
	save_size(*line, &filler->token_size_x, &filler->token_size_y);
	filler->token = (char**)malloc(sizeof(char*) * filler->token_size_y);
	while (++y < filler->token_size_y && get_next_line(FD, line) > 0)
	{
		x = -1;
		filler->token[y] = (char*)malloc(filler->token_size_x + 1);
		while (++x < filler->token_size_x)
			filler->token[y][x] = (*line)[x];
		ft_strdel(line);
	}
}

void			save_map(char **line, t_f *filler)
{
	int	i;
	int	j;
	int	s;
	int	len_line;

	if (filler->map_size_x == 0 || filler->map_size_y == 0)
		save_size(*line, &filler->map_size_x, &filler->map_size_y);
	get_next_line(FD, line);
	ft_strdel(line);
	if (filler->map == NULL)
		filler->map = (char**)ft_memalloc(sizeof(char*) * filler->map_size_y);
	j = -1;
	len_line = 0;
	while (++j < filler->map_size_y && get_next_line(FD, line) > 0)
	{
		i = -1;
		if (filler->map[j] == NULL)
			filler->map[j] = (char*)malloc(filler->map_size_x + 1);
		len_line = (len_line == 0) ?
					ft_strlen(*line) - filler->map_size_x : len_line;
		s = len_line - 1;
		while (++i < filler->map_size_x)
			filler->map[j][i] = (*line)[++s];
		ft_strdel(line);
	}
}
