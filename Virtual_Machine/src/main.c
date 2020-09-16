/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:15:00 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:01:30 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	set_vis(t_game *cw, t_player *players)
{
	if (cw->flag.vflag == 1)
	{
		cw->v = v_start_visualizer();
		v_print_arena(cw, players);
	}
	else
		cw->v = NULL;
}

int		main(int argc, char **argv)
{
	t_player	*players;
	t_game		*cw;
	int			winner;
	t_flag		flag;

	players = (t_player*)ft_memalloc(sizeof(t_player));
	players->data = (t_header*)ft_memalloc(sizeof(t_header));
	if (argc < 2 || ft_strcmp(argv[1], "-u") == 0)
		usage();
	flag = check_args(argv, argc, players);
	read_args(argv, players);
	intro_players(players);
	cw = game_set_par(players);
	cw->flag = flag;
	set_vis(cw, players);
	winner = game_loop(cw);
	if (cw->v != NULL)
	{
		endwin();
		free(cw->v);
	}
	kill_all_cursors(cw);
	free(cw);
	ft_printf("Contestant %i, \"%s\", has won !\n", winner, \
	get_winner(players, winner));
	free_players(players);
	return (0);
}
