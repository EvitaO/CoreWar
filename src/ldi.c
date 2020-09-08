/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:58:56 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/08 15:06:55 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ldi(t_cursor *c, t_game *cw)
{
	int arg1;
	int arg2;
	int pos;

	if (c->ins->arg_type[0] == T_IND)
	{
		pos = get_pos(c->c_pos, c->ins->arg1 % IDX_MOD);
		arg1 = get_argument(cw, 4, pos);
	}
	else if (c->ins->arg_type[0] == T_DIR)
		arg1 = c->ins->arg1;
	else
		arg1 = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_REG)
		arg2 = c->reg[c->ins->arg2];
	else
		arg2 = c->ins->arg2;
	c->reg[c->ins->arg3] = get_argument(cw, 4, get_pos(c->c_pos, (arg1 + arg2) % IDX_MOD));
	if (c->reg[c->ins->arg3])
		c->carry = 1;
	else
		c->carry = 0;
	return (0);
}
