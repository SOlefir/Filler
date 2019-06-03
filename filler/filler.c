/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:40:27 by solefir           #+#    #+#             */
/*   Updated: 2019/06/03 18:32:36 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //

int             do_step(t_f *filler)
{
    (void)filler;
}

static _Bool    crossing_border(t_f *filler, int y, int x)
{
    int     j;
    int     i;

    j = -1;
    while (++j < filler->token_size_y)
    {
        i = -1;
        while (++i < filler->token_size_x)
            if (filler->token[j][i] == '*' &&
                (y + j) > filler->map_size_y && (x + i) > filler->map_size_x)
                return (1);
    }
    return (0);
}


static _Bool    crossing_enemy_char(t_f *filler, int y, int x)
{
    int     j;
    int     i;
    
    j = -1;
    while (++j < filler->token_size_y)
    {
        i = -1;
        while (++i < filler->token_size_x)
            if (filler->token[j][i] == '*' &&
                (filler->map[y + j][x + i] == filler->enemy ||
                filler->map[y + j][x + i] == (filler->enemy + 32)))
                return (1);
    }
    return (0);
}

static _Bool    crossing_my_char(t_f *filler, int y, int x)
{
    int     j;
    int     i;
    char    my_char;

    my_char = (filler->enemy == 'X') ? 'O' : 'X';
    j = -1;
    while (++j < filler->token_size_y)
    {
        i = -1;
        while (++i < filler->token_size_x)
            if (filler->token[j][i] == '*' &&
                (filler->map[y + j][x + i] == my_char ||
                filler->map[y + j][x + i] == (my_char + 32)))
                return (1);
    }
    return (0);
}

void		decision(t_f *filler)
{
    int y;
    int x;

    y = -1;
    while (++y < filler->map_size_y &&
    filler->map_size_y <= (filler->token_size_y + y))
    {
        x = -1;
        while (++x < filler->map_size_x &&
        filler->map_size_x <= (filler->token_size_x + x))
        {
            if (!crossing_border(filler, y, x) &&
                crossing_my_char(filler, y, x) &&
                !(crossing_enemy_char(filler, y, x)))
                //do_step(filler);
                printf()
        }
    }
}
