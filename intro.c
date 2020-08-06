/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intro.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 13:02:30 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/06 17:50:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void            intro_players(t_player *players)
{
    ft_printf("Introducing contestants...\n");
    while (players)
	{
		//ft_printf("File is %s.cor\n\n", players->fname);
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", players->id, players->data->prog_size, players->data->prog_name, players->data->comment);
		players = players->next;
	}
}