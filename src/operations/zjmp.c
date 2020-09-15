/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 15:55:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 14:02:05 by eovertoo      ########   odam.nl         */
/*   Updated: 2020/09/15 12:37:52 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** zjmp get an index defined by c->ins->arg1 (T_DIR)
** if carry == 1 then cursor moves to (c->c_pos + (index % IDX_MOD)) % MEM_SIZE
** else move cursor 2 bytes
*/

int				zjmp(t_cursor *c, t_game *cw)
{
	(void)cw;
	if (c->carry == 1)
	{
		//ft_printf("jumps from %i ", c->c_pos);
		c->c_pos = (c->c_pos + (c->ins->arg1 % IDX_MOD)) % MEM_SIZE;
		while (c->c_pos < 0)
			c->c_pos = c->c_pos + MEM_SIZE;
		//ft_printf("to %i\n", c->c_pos);
	}
	else
	{
		//ft_printf("zjmp failed\n");
		c->c_pos = get_pos(c->c_pos, 3);
	}
	return (0);
}
