/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:15:00 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/24 14:25:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			main(int argc, char **argv)
{
	t_player	*players;

	players = (t_player*)ft_memalloc(sizeof(t_player));
	players->data = (header_t*)ft_memalloc(sizeof(header_t));
	if (argc < 2 || ft_strcmp(argv[1], "-u") == 0)
		usage();
	check_arg(argc, argv, players);
	exit(1);
	read_args(argv, players);
	intro_players(players);
	game_set_par(players);
	free_players(players);
	return (0);
}
