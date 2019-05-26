/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/05/26 18:13:44 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <fcntl.h>
#include <unistd.h>
#include "../GNL/get_next_line.h"

typedef	struct s_f
{
	int		*map_size;
	int		**distance;
	int		**sit_enemy;
	char	enemy;
	char	**map;
	char	**token;
	char	my_step;
}				t_f;

void	make_arr(t_f *filler);

#endif