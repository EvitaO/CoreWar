/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 16:02:14 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/08 14:05:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ld(t_cursor *c, t_game *cw)
{
	int arg;
	int pos;

	if (c->ins->arg_type[0] == T_IND)
	{
		pos = get_pos(c->c_pos, c->ins->arg1 % IDX_MOD);
		arg = get_argument(cw, 4, pos);
	}
	else
		arg = c->ins->arg1;
	c->reg[c->ins->arg2] = arg;
	if (arg)
		c->carry = 1;
	else
		c->carry = 0;
	return (0);
}
