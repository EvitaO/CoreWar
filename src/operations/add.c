/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:27:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 12:02:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		add(t_cursor *c, t_game *cw)
{
	int new;

	if (!cw)
		return (0);
	new = c->reg[c->ins->arg1] + c->reg[c->ins->arg2];
	c->reg[c->ins->arg3] = new;
	//ft_printf("add:	r%i	r%i	r%i		cycle	%i\n", c->ins->arg1, c->ins->arg2, c->ins->arg3, cw->cycles_cnt);
	if (new != 0)
	{
		c->carry = 0;
		return (1);
	}
	else
		c->carry = 1;
	return (0);
}
