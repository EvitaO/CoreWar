/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_set_par.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:04:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/24 14:24:38 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			set_game_data(t_game *game, t_player *players)
{
	game->players = count_players(players);
	game->player_l_alive = game->players;
	game->cycles_cnt = 0;
	game->live_cnt = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks_cnt = 0;
}

void			game_set_par(t_player *players)
{
	t_game		*game_data;
	t_cursor	*cursors;

	game_data = (t_game *)ft_memalloc(sizeof(t_game));
	set_game_data(game_data, players);
	game_setup(players, game_data);
	cursors = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	set_cursors(cursors, players);
	free_cursor(cursors);
	free(game_data);
}