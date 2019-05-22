/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:17 by solefir           #+#    #+#             */
/*   Updated: 2019/05/22 21:14:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <fcntl.h>
#include <unistd.h>
#include "../GNL/get_next_line.h"

typedef	struct s_filler
{
	int		*map;
	char	p; // p1 or p2
	char	**sit_enemy;
	char	**map; // с просчётом дистанции к врагу
	char	**token; // место в массиве (индекс Х / У)
	char	my_step; // "X Y\n"
}				t_filler;



#endif