/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:57:02 by solefir           #+#    #+#             */
/*   Updated: 2019/07/03 15:29:47 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	del_token(t_f *filler)
{
	int	i;

	i = -1;
	if (filler->token != NULL)
	{
		while (++i < filler->token_size_y)
			if (filler->token[i] != NULL)
			{
				free(filler->token[i]);
				filler->token[i] = NULL;
			}
		free(filler->token);
		filler->token = NULL;
	}
}

int				main(void)
{
	char			*line;
	t_f				*filler;

	line = NULL;
	filler = (t_f*)ft_memalloc(sizeof(t_f));
	get_next_line(FD, &line);
	filler->enemy = (line[10] == '1') ? 'X' : 'O';
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
	{
		save_map(&line, filler);
		get_next_line(FD, &line);
		save_token(&line, filler);
		make_arr_distance(filler);
		decision(filler);
		del_token(filler);
	}
	return (0);
}
