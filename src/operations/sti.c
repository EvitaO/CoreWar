/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 15:51:08 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 16:30:18 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

// "Value from the Argument1 is written to the memory, to the address: 
// current_position + ((Argument2 + Argument3) % IDX_MOD)
// If Argument2 is of type T_IND, value (4 bytes) for address calculation is read from memory: 
// current_position + (Argument2 % IDX_MOD)"

// sti: Opcode 11. Take a registry, and two indexes (potentially registries) add the
// two indexes, and use this result as an address where the value of the first parameter
// will be copied.

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
