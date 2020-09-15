/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:30:04 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 11:41:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		sub(t_cursor *c, t_game *cw)
{
	int new;

	if (!cw)
		return (0);
	new = c->reg[c->ins->arg1] - c->reg[c->ins->arg2];
	c->reg[c->ins->arg3] = new;
	//ft_printf("Sub:	res	%i	r%i	r%i	r%i\n", new, c->ins->arg1, c->ins->arg2, c->ins->arg3);
	if (new != 0)
	{
		c->carry = 0;
		return (1);
	}
	else
		c->carry = 1;
	return (0);
}
