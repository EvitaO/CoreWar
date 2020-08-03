/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intro.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 13:02:30 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/03 13:04:53 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void            intro_players(t_player *players)
{
    ft_printf("Introducing contestants...\n");
    while (players)
	{
		//ft_printf("File is %s.cor\n\n", players->fname);
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", players->id, players->size, players->name, players->comment);
		players = players->next;
	}
}