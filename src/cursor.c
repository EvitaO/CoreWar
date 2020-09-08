/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:28:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 11:28:43 by anonymous     ########   odam.nl         */
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
		free(c);
	}
	else
	{
		if (c->prev)
		{
			c->prev->next = NULL;
			cw->c = c->prev;
			free(c);
		}
		else
			cw->c = NULL;
	}
}