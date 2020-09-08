/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nflag.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 10:55:23 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/08 13:39:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		check_flags(char *arg, t_flag *flags)
{
	if (ft_strcmp(arg, "-a") == 0)
		flags->aflag = 1;
	else if (ft_strcmp(arg, "-v") == 0)
		flags->vflag = 1;
	else
		return (-1);
	return (0);
}

static void			proces_nflag(t_player *players, int n, int max_pl)
{
	int		arr[max_pl];

	set_arr_m1(max_pl, arr);
	arr[n] = players->arg_n;
	n = find_n(&players, players->arg_n, max_pl);
	while (n != -1)
		n = check_find_n(&players, arr, n, max_pl);
	add_to_arr(players, arr, max_pl);
	adjust_id(players, arr, max_pl);
}

void				ft_nflag(t_player *players)
{
	int			i;
	int			cnt;

	cnt = count_players(players);
	i = find_n(&players, -1, cnt);
	if (i < 0)
		return ;
	proces_nflag(players, i, cnt);
	sort_players(&players);
}
