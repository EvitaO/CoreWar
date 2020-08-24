/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cursors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 16:09:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/24 13:48:54 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			add_cursor(t_cursor **cursor)
{
	(*cursor)->prev = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	(*cursor)->prev->next = *cursor;
	*cursor = (*cursor)->prev;
}

void			set_cursors(t_cursor *cursors, t_player *players)
{
	while (players->next)
	{
		cursors->c_pos = players->cursor;
		cursors->id = players->id;
		add_cursor(&cursors);
		players = players->next;
	}
	cursors->c_pos = players->cursor;
	cursors->id = players->id;
	// while (cursors)
	// {
	//     ft_printf("%i   %i\n", cursors->pos, cursors->id);
	//     cursors = cursors->next;
	// }
}
