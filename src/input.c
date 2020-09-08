/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/07 13:48:12 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/08 13:04:41 by anonymous     ########   odam.nl         */
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

// int			check_arg(int argc, char **argv, t_player *players)
// {
// 	int			i;
// 	char		**name;
// 	int			n;
// 	int			pl;
// 	int			aflag;

// 	i = 1;
// 	n = 0;
// 	aflag = 0;
// 	pl = count_args(argv, argc);
// 	while (i < argc)
// 	{
// 		if (!ft_strcmp(argv[i], "-n"))
// 		{
// 			check_nflag(players, argv[i + 1], &n);
// 			i++;
// 		}
// 		else if (str_ending(argv[i], ".cor") == 0)
// 		{
// 			name = ft_strsplit(argv[i], '.');
// 			give_id(players, name, n, i);
// 			add_node(&players, &pl);
// 			free_arr(name);
// 		}
// 		else if (ft_strcmp(argv[i], "-a") == 0)
// 			aflag = 1;
// 		else
// 			exit(ft_printf("arg is not a '.cor' file\n"));
// 		i++;
// 	}
// 	ft_nflag(players);
// 	while (players->prev)
// 		players = players->prev;
// 	while (players->next)
// 	{
// 		ft_printf("Player %i is %s\n", players->id, players->fname);
// 		players = players->next;
// 	}
// 	ft_printf("Player %i is %s\n", players->id, players->fname);
// 	return (aflag);
// }
