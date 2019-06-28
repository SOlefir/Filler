/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/06/28 19:49:31 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <fcntl.h>
#include <unistd.h>
#include "../GNL/get_next_line.h"

# define ABS(x) ((x < 0) ? (-(x)) : (x))

typedef	struct s_f
{
	int		map_size_x;
	int		map_size_y;
	int		token_size_x;
	int		token_size_y;
	int		**distance;

	int		my_step_y;
	int		my_step_x;
	int		min_distance_sum;

	char	enemy;
	char	**map;
	char	**token;
}				t_f;

void	make_arr_distance(t_f *filler);
void	decision(t_f *filler);
void	chek_step(t_f *filler, int y, int x);
void	print_map_and_step(t_f *filler);//

#endif