/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 15:32:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/25 15:08:47 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		execute_operation(t_cursor *c, t_game *cw)
{
	int ret;

	ret = 0;
	if (c->op > 16)
		return (1);
	if (!encoding_byte(cw->arena[get_pos(c->c_pos, 1)], c->ins, &ret))
	{
		c->p_pos = c->c_pos;
		c->c_pos = get_pos(c->c_pos, size_of_arg(*(c->ins)));
		return (0);
	}
	// HIER MOET NOG IETS KOMEN MAAR IS AFHANKELIJK VAN FUNCTIE POINTER ARRAY DIE ER NOG NIET IS
	free(c->ins);
	c->ins = NULL;
	return (1);
}

void	get_operation(t_cursor *c, t_game *cw)
{
	t_instruction	*ins;

	c->op = cw->arena[c->c_pos];
	if (c->op > 16)
		c->wait = 0;
	else
	{
		ins = new_instruction();
		ins->op = cw->arena[c->c_pos];
		c->ins = ins;
		c->wait = g_op_tab[ins->op - 1].cycles;
	}
}
