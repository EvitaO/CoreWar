/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:16:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/13 15:47:10 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	fork copies the cursor to (c->ins->arg1 % IDX_MOD) + current_position
**	arg1 is a T_DIR
**	lfork does the same but without % IDX_MOD
*/

static void	add_cur(t_game *cw, t_cursor *new)
{
	if (new == NULL)
		return ;
	new->next = NULL;
	new->prev = cw->c;
	cw->c->next = new;
	cw->c = cw->c->next;
}

int			op_fork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = NULL;
	new->op = -1;
	new->c_pos = (c->c_pos + (c->ins->arg1 % IDX_MOD)) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	add_cur(cw, new);
	return (0);
}

int			lfork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = NULL;
	new->op = -1;
	new->c_pos = (c->c_pos + c->ins->arg1) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	add_cur(cw, new);
	return (0);
}
