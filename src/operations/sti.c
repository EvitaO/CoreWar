/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 15:51:08 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 18:15:55 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	sti gets 3 arguments and writes the value of argument1 to an address
**	if argument2 is a T_IND the address is:
**	current_position + (argument2 % IDX_MOD)
**	else the address is:
**	current_position + ((argument2 + argument3) % IDX_MOD)
**	arg1		T_REG
**	arg2		T_REG/T_DIR/T_IND
**	arg3		T_REG/T_DIR
*/

int				sti(t_cursor *c, t_game *cw)
{
	int			dst;

	c->ins->arg1 = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_REG)
		c->ins->arg2 = c->reg[c->ins->arg2];
	else if (c->ins->arg_type[1] == T_IND)
		dst = c->c_pos + ((c->ins->arg2 % IDX_MOD) % MEM_SIZE);
	if (c->ins->arg_type[2] == T_REG)
		c->ins->arg3 = c->reg[c->ins->arg3];
	if (c->ins->arg_type[1] != T_IND)
		dst = c->c_pos + (((c->ins->arg2 + c->ins->arg3) % IDX_MOD)) % MEM_SIZE;
	while (dst < 0)
		dst = dst + MEM_SIZE;
	cw->arena[dst] = c->ins->arg1;
	return (0);
}
