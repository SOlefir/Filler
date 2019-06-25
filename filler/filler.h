/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/06/21 19:38:25 by solefir          ###   ########.fr       */
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

	int		min_distance;

	char	enemy;
	char	**map;
	char	**token;
	char	*my_step;
}				t_f;

void	make_arr_distance(t_f *filler);
void	distance(t_f *filler);
int		min_distance_sum(t_f *filler, int distance, int y, int x);

#endif