/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/05/27 19:56:57 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

static void		save_size(char *line, int **size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != ' ')
		i++;
	while (line[++i] != ':')
	{
		if (line[i] >= '0' && line[i] <= '9')
			(*size)[j] = ((*size)[j] * 10) + line[i] - '0';
		else
			j++;
	}
}

static void		save_token(char **line, t_f *filler)
{
	int	i;
	int j;
	int	*size;

	size = (int*)ft_memalloc(sizeof(int) * 2);
	save_size(*line, &size);
	free(*line);
	j = 0;
	i = 0;
	filler->token = (char**)malloc(sizeof(char*) * size[0]);
	while (get_next_line(3, line) > 0 && j < size[0])
	{
		filler->token[j] = (char*)malloc(size[1]);
		while (i < size[1])
		{
			filler->token[j][i] = (*line)[i];
			i++;
		}
		filler->token[j][i] = '\0';
		free(*line);
		j++;
		i = 0;
	}
	free(size);
}

static void		save_map(char *line, t_f *filler, int j)
{
	int	i;
	int	s;

	s = ft_strlen(line);
	i = 0;
	filler->map[j] = (char*)malloc(filler->map_size[1] + 1);
	s = s - filler->map_size[1];
	while (i <= filler->map_size[1])
	{
		filler->map[j][i] = line[s];
		s++;
		i++;
	}
}

static t_f		*make_struct(t_f *filler, char **line)
{
	filler = (t_f*)ft_memalloc(sizeof(t_f));
	filler->enemy = (*line[10] == '1') ? 'O' : 'X';
	free(*line);
	get_next_line(3, line);
	filler->map_size = (int*)ft_memalloc(sizeof(int) * 2);
	save_size(*line, &filler->map_size);
	free(*line);
	filler->map = (char**)malloc(sizeof(char*) * filler->map_size[0]);
	return (filler);
}

int				main(void)
{
	char			*line;
	int				j;
	t_f				*filler;

	line = NULL;
	open("return.txt", O_RDONLY);
	get_next_line(3, &line);
	filler = make_struct(filler, &line);
	j = -1;
	printf("____\n");
	while (get_next_line(3, &line) > 0)
	{
		if (line[0] > 32 && ++j != filler->map_size[0])
		{
			save_map(line, filler, j);
			printf("%s\n", filler->map[j]);
		}
		else if (line[0] == 'P')
			save_token(&line, filler);
		else
			free(line);
	}
	do_step(filler);
	printf("%s\n%s\n", filler->token[0], filler->token[1]);
	return (0);
}
