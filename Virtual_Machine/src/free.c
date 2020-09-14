/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 17:31:35 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/14 15:28:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			free_cursor(t_cursor *cursors)
{
	t_cursor	*tmp;

	while (cursors)
	{
		tmp = cursors->prev;
		free(cursors);
		cursors = tmp;
	}
	free(cursors);
}

void			free_players(t_player *players)
{
	t_player	*tmp;

	while (players)
	{
		tmp = players->next;
		free(players->data);
		free(players->code);
		free(players);
		players = tmp;
	}
	free(players);
}
