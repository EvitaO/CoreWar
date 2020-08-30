/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:16:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/28 16:53:50 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** copy cursor to (c->ins->arg1 % IDX_MOD) + c->c_pos
*/

void		fork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft memallac(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = (t_instruction*)ft_memset(new->ins, 0, sizeof(t_instruction));
	new->c_pos = (c->c_pos + (c->ins->arg1 % IDX_MOD)) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	new->prev = cw->c;
	new->next = cw->c->next;
}

void		lfork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft memallac(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = (t_instruction*)ft_memset(new->ins, 0, sizeof(t_instruction));
	new->c_pos = (c->c_pos + c->ins->arg1) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	new->prev = cw->c;
	new->next = cw->c->next;
}
