/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:28:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/10 13:12:23 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	kill_cursor(t_game *cw, t_cursor *c)
{
	if (c->next)
	{
		if (c->prev)
			c->prev->next = c->next;
		c->next->prev = c->prev;
		if (c->ins)
			free(c->ins);
		free(c);
	}
	else
	{
		if (c->prev)
		{
			c->prev->next = NULL;
			cw->c = c->prev;
			if (c->ins)
				free(c);
			free(c);
		}
		else
			cw->c = NULL;
	}
}

void	kill_all_cursors(t_game *cw)
{
	t_cursor *temp1;
	t_cursor *temp2;

	temp1 = cw->c;
	while (temp1)
	{
		temp2 = temp1->prev;
		if (temp1->ins)
			free(temp1->ins);
		free(temp1);
		if (temp2)
			temp1 = temp2;
	}
}
