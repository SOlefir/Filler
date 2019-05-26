/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/05/26 22:46:27 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //
static void		save_token(char **line, t_f *filler)
{
	int	i;
	int j;
	int	size[2] = {0, 0};

	i = 0;
	j = 0;
	printf("sdfa1\n");
	while ((*line)[i] != ' ')
		i++;
	while ((*line)[++i] != ':')
	{
		if ((*line)[i] >= '0' && (*line)[i] <= '9')
			size[j] = (size[j] * 10) + (*line)[i] - '0';
		if ((*line)[i] == ' ')
			j++;
	}
	printf("sdfa2\n");
	//free(*line);
	j = 0;
	i = 0;
	filler->token = (char**)malloc(sizeof(char*) * size[0]);
	filler->token[j] = (char*)malloc(size[1]);
	while (get_next_line(3, line) > 0 && j <= size[0])
	{
		while (i < size[1])
		{
			filler->token[j][i] = (*line)[i];
			i++;
		}
		if (i == size[1])
		{	
			filler->token[j][i] = '\0';
			j++;
			filler->token[j] = (char*)malloc(size[1]);
			i = 0;
		}
		printf("-> %p \n", line);
		printf("-> %p \n", *line);
		//printf("[%s]\n", filler->token[j]);
		//free(*line);
	}
	printf("\n_____________________________________\n");
}

static void		save_map(char **line, t_f *filler, int j)
{
	int	i;
	int	s;

	s = ft_strlen(*line);
	i = 0;
	filler->map[j] = (char*)malloc(filler->map_size[1] + 1);
	s = s - filler->map_size[1];
	while (i != filler->map_size[1])
	{
		filler->map[j][i] = (*line)[s];
		s++;
		i++;
	}
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
	printf("size: y[%d] x[%d]\n", filler->map_size[0], filler->map_size[1]);
}

static void		make_struct(t_f **filler, char **line, int i)
{
	*filler = (t_f*)ft_memalloc(sizeof(t_f));
	(*filler)->enemy = (*line[10] == '1') ? 'O' : 'X';
	free(*line);
	get_next_line(i, line);
	save_map_size(*line, *filler);
	(*filler)->map = (char**)malloc((*filler)->map_size[0]);
}

int				main(void)
{
	char			*line;
	int				j;
	int				i;
	static t_f		*filler = NULL;

	line = NULL;
	i = open("return.txt", O_RDONLY);
	get_next_line(i, &line);
	if (filler == NULL)
		make_struct(&filler, &line, i);
	free(line);
	j = 0;
	printf("\nmap:\n");
	while (get_next_line(i, &line) > 0)
	{
		if (line[0] > 32 && j < filler->map_size[0])
		{
			save_map(&line, filler, j);
			printf("%s\n", filler->map[j]);
			j++;
		}
		else if (j == filler->map_size[0])
		{
			//printf("sdfa\n");
			save_token(&line, filler);
		}
		printf("sdfa44\n");
	}
	//make_arr(filler);*/
	return (0);
}
