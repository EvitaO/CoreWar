/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 15:55:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/28 16:52:21 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** zjmp get an index defined by c->ins->arg1
** if carry == 1 then cursor moves to (c->c_pos + (index % IMX_MOD)) % MEM_SIZE
** modulo mem_size to make sure c_pos doesnt get bigger then MEM_SIZE
** else move cursor 2 bytes
*/

void			zjmp(t_cursor *c, t_game *cw)
{
	if (c->carry == 1)
	{
		c->c_pos = (c->c_pos + (c->ins->arg1 % IMX_MOD)) % MEM_SIZE;
		while (c->c_pos < 0)
			c->c_pos = c->c_pos + MEM_SIZE;
	}
	else
		c->c_pos = get_pos(c->c_pos, 2);
	return ;
}
