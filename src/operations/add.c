/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:27:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 12:51:57 by eutrodri      ########   odam.nl         */
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
	if (new == 0)
	{
		c->carry = 1;
		return (1);
	}
	else
		c->carry = 0;
	return (0);
}
