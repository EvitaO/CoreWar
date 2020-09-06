/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:16:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 16:47:32 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** copy cursor to (c->ins->arg1 % IDX_MOD) + c->c_pos
*/

static void	add_cur(t_cursor **c, t_cursor *new)
{
	if (new == NULL)
		return ;
	while ((*c)->prev)
		*c = (*c)->prev;
	new->prev = NULL;
	new->next = *c;
	(*c)->prev = new;
}

int			op_fork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = (t_instruction*)ft_memset(new->ins, 0, sizeof(t_instruction));
	new->c_pos = (c->c_pos + (c->ins->arg1 % IDX_MOD)) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	add_cur(&cw->c, new);
	return (0);
}

int			lfork(t_cursor *c, t_game *cw)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	new = (t_cursor*)ft_memcpy(new, c, sizeof(t_cursor));
	new->ins = (t_instruction*)ft_memset(new->ins, 0, sizeof(t_instruction));
	new->c_pos = (c->c_pos + c->ins->arg1) % MEM_SIZE;
	while (new->c_pos < 0)
		new->c_pos = new->c_pos + MEM_SIZE;
	add_cur(&cw->c, new);
	return (0);
}
