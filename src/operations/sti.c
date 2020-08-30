/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 15:51:08 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/28 16:54:18 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/h"

// "Value from the Argument1 is written to the memory, to the address: 
// current_position + ((Argument2 + Argument3) % IDX_MOD)
// If Argument2 is of type T_IND, value (4 bytes) for address calculation is read from memory: 
// current_position + (Argument2 % IDX_MOD)"

// sti: Opcode 11. Take a registry, and two indexes (potentially registries) add the
// two indexes, and use this result as an address where the value of the first parameter
// will be copied.

void			sti(t_cursor *c, t_game *cw)
{
	int			dst;

	if (c->ins->arg2_type == T_IND)
		dst = c->c_pos + ((c->ins->arg2 % IDX_MOD) % MEM_SIZE);
	else
		dst = c->c_pos + (((c->ins->arg2 + c->ins->arg3) % IDX_MOD)) % MEM_SIZE);
	while (dst < 0)
		dst = dst + MEM_SIZE;
	cw->arena[dst] = c->inst->arg1;
}
