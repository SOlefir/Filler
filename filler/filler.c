/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/05/24 20:23:22 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		save_token(char *line, t_f *filler)
{

}

static void		save_map(char *line, t_f *filler, int j)
{
	int	i;

	i = filler->map_size[1];
	filler->map[j] = (char*)malloc(i);
	filler->map[j][i] = '\0';
	while (--i >= 0 && line[0] > 32)
		filler->map[j][i] = line[i];
}

static void		save_size_map(char *line, t_f *filler)
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

	get_next_line(0, &line);
	if (!filler)
	{
		filler = (t_f*)ft_memalloc(sizeof(t_f));
		filler->enemy = (line[10] == 1) ? "X" : "O";
		free(line);
		get_next_line(0, &line);
		save_size_map(line, filler);
		filler->map = (char**)malloc(filler->map[1]);
		filler->distance = (int**)malloc(filler->map[1]);
	}
	free(line);
	j = filler->map_size[0];
	while (get_next_line(0, &line) > 0)
	{
		if (--j >= 0)
			save_map(line, &filler, j);
		else
			save_token(line, &filler);
		free(line)
	}
	return (filler->my_step);
}
