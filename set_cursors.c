/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cursors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 16:09:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/09 16:16:32 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//  int                 id;
//     int                 carry;
//     int                 last_live;
//     int                 wait_cycles;
//     int                 pos;
//     int                 jump;
//     int                 reg[REG_NUMBER];
//     struct s_cursors    *next;
//     struct s_cursors    *prev;

void            set_cursors(t_cursors *cursors, t_player *players)
{
    while (players->next)
    {
        ft_printf("%s   %i\n", players->data->prog_name, players->id);
        cursors->pos = players->cursor;
		cursors->id = players->id;
        players = players->next;
    }
    ft_printf("%s   %i\n", players->data->prog_name, players->id);
}
