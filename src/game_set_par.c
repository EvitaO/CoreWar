/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_set_par.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:04:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/25 14:27:50 by anonymous     ########   odam.nl         */
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

	game_data = (t_game *)ft_memalloc(sizeof(t_game));
	set_game_data(game_data, players);
	game_setup(players, game_data);
	game_data->c = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	set_cursors(game_data->c, players);
	game_loop(game_data);
	free_cursor(game_data->c);
	free(game_data);
}
