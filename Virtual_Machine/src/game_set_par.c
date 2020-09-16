/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_set_par.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:04:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/16 17:48:56 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			set_game_data(t_game *game, t_player *players)
{
	game->players = count_players(players);
	game->player_l_alive = game->players;
	game->cycles_cnt = 0;
	game->live_cnt = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks_cnt = 0;
	game->die_cnt = CYCLE_TO_DIE;
}

t_game			*game_set_par(t_player *players)
{
	t_game		*game_data;
	t_cursor	*cursors;

	game_data = (t_game *)ft_memalloc(sizeof(t_game));
	set_game_data(game_data, players);
	game_setup(players, game_data);
	cursors = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	set_cursors(cursors, players);
	while (cursors->prev)
		cursors = cursors->prev;
	game_data->c = cursors;
	return (game_data);
}
