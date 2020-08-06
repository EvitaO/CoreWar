/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:15:00 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/06 18:13:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			count_players(t_player *players)
{
	int		cnt;

	cnt = 1;
	while (players->next)
	{
		players = players->next;
		cnt++;
	}
	while (players->prev)
		players = players->prev;
	return(cnt);
}

void		give_start_cursor(t_player *players, int cnt_pl, unsigned char *arena)
{
	while (players->next)
	{
		players->cursor = (MEM_SIZE / cnt_pl) * (players->id - 1);
		ft_memcpy(&arena[players->cursor], players->code, CHAMP_MAX_SIZE);
		players = players->next;
	}
	players->cursor = (MEM_SIZE / cnt_pl) * (players->id - 1);
	ft_memcpy(&arena[players->cursor], players->code, CHAMP_MAX_SIZE);
	while (players->prev)
		players = players->prev;
}

void		game_setup(t_player *players)
{
	unsigned char	*arena;
	int				cnt_pl;
	int				i;

	i = 0;
	arena = (unsigned char *)ft_memalloc(sizeof(unsigned char) * MEM_SIZE + 1);
	cnt_pl = count_players(players);
	give_start_cursor(players, cnt_pl, arena);
	while (i <= MEM_SIZE)
	{
		ft_printf("%x ", arena[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_player    *players;

	players = (t_player*)ft_memalloc(sizeof(t_player));
	players->data = (header_t*)ft_memalloc(sizeof(header_t));
	if (argc < 2)
		ft_printf("Not enough arguments\n");
	check_arg(argc, argv, players);
	read_args(argv, players);
	intro_players(players);
	game_setup(players);
	return (0);
}
