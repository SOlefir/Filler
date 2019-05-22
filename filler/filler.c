/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:47:47 by solefir           #+#    #+#             */
/*   Updated: 2019/05/22 21:53:03 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char		*line;
	int			i;
	int			j;
	t_filler	filler;

	i = 7;
	j = 0;
	get_next_line(0, &line);
	filler.p = (line[10] == 1) ? "O" : "X";
	get_next_line(0, &line);
	while (line[++i] != ':')
	{
		if (line[i] >= '0' && line[i] <= '9')
			filler.map_size[j] = line[i] - '0';
		else
			j++;
	}
	j = 0;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		while (line[i] == '.')
			filler.map[j][i] = line[i++];
		j++;
		
	}
	


}
