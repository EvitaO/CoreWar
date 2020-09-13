/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nflag.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 10:55:23 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/13 14:26:53 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			check_flags(char **arg, t_flag *flags, int *i)
{
	if (ft_strcmp(arg[*i], "-a") == 0)
		flags->aflag = 1;
	else if (ft_strcmp(arg[*i], "-v") == 0)
		flags->vflag = 1;
	else if (ft_strcmp(arg[*i], "-dump") == 0 || ft_strcmp(arg[*i], "-d") == 0)
	{
		if (ft_strcmp(arg[*i], "-dump") == 0)
			flags->mod = 32;
		else
			flags->mod = 64;
		if (arg[*i + 1] && ft_isdigit(arg[*i + 1][0]) == 1)
		{
			flags->dump_flag = ft_atoi2(arg[*i + 1]);
			if (flags->dump_flag <= 0)
				exit(ft_printf("Error number has to be higher then 0\n"));
			(*i)++;
		}
		else
			exit(ft_printf("not a valid use of '%s' flag\n", arg[*i]));
	}
	else
		return (-1);
	return (0);
}

static void	proces_nflag(t_player *players, int n, int max_pl)
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

void		ft_nflag(t_player *players)
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
