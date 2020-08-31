/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cursors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 16:09:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/31 13:07:54 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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
		cursors->live = 0;
		cursors->jump = 0;
		cursors->ins = NULL;
		cursors->op = -1;
		cursors->carry = 0;
		cursors->p_pos = -1;
		cursors->reg[0] = players->id;
		add_cursor(&cursors);
		players = players->next;
	}
	cursors->reg[0] = players->id;
	cursors->c_pos = players->cursor;
	cursors->id = players->id;
	cursors->live = 0;
	cursors->jump = 0;
	cursors->ins = NULL;
	cursors->op = -1;
	cursors->carry = 0;
	cursors->p_pos = -1;
	// while (cursors)
	// {
	//     ft_printf("%i   %i\n", cursors->pos, cursors->id);
	//     cursors = cursors->next;
	// }
}
