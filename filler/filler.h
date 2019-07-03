/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/07/03 15:24:15 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <fcntl.h>
#include <unistd.h>
#include "../GNL/get_next_line.h"

# define FD 3
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

void		save_token(char **line, t_f *filler);
void		save_map(char **line, t_f *filler);
void		make_arr_distance(t_f *filler);
void		decision(t_f *filler);


#endif