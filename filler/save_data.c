/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/05/25 20:05:16 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //
static void		save_token(char *line, t_f *filler)
{
	int	i;
	int j;
	int	size[2];

	i = 0;
	j = 0;
	while (line[0] == 'P' && line[++i] != ':')
	{
		if (line[i] >= '0' && line[i] <= '9')
			size[j] = (size[j] * 10) + line[i] - '0';
		else
			j++;
	}
	i = size[1];
	filler->token[j] = (char*)malloc(i);
	filler->token[j][i] = '\0';
	while (--i >= 0)
		filler->token[j][i] = line[i];
}

static void		save_map(char *line, t_f *filler)
{
	int	i;
	int	j;
	int	s;

	s = ft_strlen(line) + 1;//22
	j = filler->map_size[0];//15
	i = filler->map_size[1] + 1;//17+1
	printf("str_len %d\n", s);
	printf("\nsave_map:\n {j = %d i = %d}\n", j, i);
	filler->map[j] = (char*)malloc(i);
	printf("line:%s\n", line);
	//printf("line[i] == [%c]\n", line[i]);
	while (--i >= 0)
	{
		filler->map[j][i] = line[--s];
		printf("line[s] == [%c]\n map[i] = [%c]\n", line[s], filler->map[j][i]);
		printf("(%d)(%d)\n", i, s);
	}
	printf("map[%s]\n", filler->map[j]);
}

static void		save_map_size(char *line, t_f *filler)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	filler->map_size = (int*)ft_memalloc(sizeof(int) * 2);
	while (line[++i] != ':')
	{
		if (line[i] >= '0' && line[i] <= '9')
			filler->map_size[j] = (filler->map_size[j] * 10) + line[i] - '0';
		else
			j++;
	}
}

int				main(void)
{
	char			*line;
	int				j;
	static t_f		*filler = NULL;

	j = open("return.txt", O_RDWR);
	printf("fd:%d\n", j);
	printf("gnl:%d\n", get_next_line(j, &line));
	printf("line:%s\n", line);
	if (filler == NULL)
	{
		filler = (t_f*)ft_memalloc(sizeof(t_f*));
		filler->enemy = (line[10] == '1') ? 'O' : 'X';
		printf("enemy:[%c]\n", filler->enemy);
		free(line);
		get_next_line(j, &line);
		save_map_size(line, filler);
		printf("size: y[%d] x[%d]\n", filler->map_size[0], filler->map_size[1]);
		filler->map = (char**)malloc(filler->map_size[0]);
	}
	free(line);
	j = 0;
	//printf("main map:\n");
	while (get_next_line(3, &line) > 0 || j <= (filler->map_size[0] + 1))
	{
		if (line[0] != 'P' && line[0] > 32)
		{
			printf("line:%s\n", line);
			save_map(line, filler);
			printf("%d", j);
			printf("[%s]\n", filler->map[j]);
			j++;
		}
		else if (line[0] == 'P')
			save_token(line, filler);
		free(line);
	}
	printf("token:\n");
	printf("[%s]\n", filler->token[0]);
	printf("[%s]\n", filler->token[1]);
	//make_arr(filler);
	return (0);
}
