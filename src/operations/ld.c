/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 16:02:14 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 14:25:14 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		ld(t_cursor *c, t_game *cw)
{
	int arg;
	if (c->ins->arg_type[0] == T_IND)
		arg = cw->arena[get_pos(c->c_pos, c->ins->arg1 % IDX_MOD)];
	else
		arg = c->ins->arg1;
	c->reg[c->ins->arg2] = arg;
	if (arg)
		c->carry = 1;
	else
		c->carry = 0;
	return (0);
}
