/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/05/28 18:56:50 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <fcntl.h>
#include <unistd.h>
#include "../GNL/get_next_line.h"

typedef	struct s_f
{
	int		map_size_x;
	int		map_size_y;
	int		sit_enemy_x;
	int		sit_enemy_y;
	int		my_sit_x;
	int		my_sit_y;
	int		**distance;

	char	enemy;
	char	**map;
	char	**token;
	char	my_step;
}				t_f;

//void	do_step(t_f *filler);
void	distance(t_f *filler);

#endif