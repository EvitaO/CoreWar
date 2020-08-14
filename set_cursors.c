/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cursors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 16:09:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/14 16:11:24 by anonymous     ########   odam.nl         */
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

void			add_cursor(t_cursors **cursor)
{
	(*cursor)->prev = (t_cursors *)ft_memalloc(sizeof(t_cursors));
	(*cursor)->prev->next = *cursor;
	*cursor = (*cursor)->prev;
}

void			set_cursors(t_cursors *cursors, t_player *players)
{
	while (players->next)
	{
		cursors->pos = players->cursor;
		cursors->id = players->id;
		add_cursor(&cursors);
		players = players->next;
	}
	cursors->pos = players->cursor;
	cursors->id = players->id;
	// while (cursors)
	// {
	//     ft_printf("%i   %i\n", cursors->pos, cursors->id);
	//     cursors = cursors->next;
	// }
}
