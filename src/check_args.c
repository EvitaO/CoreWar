/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 19:30:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 15:28:05 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	add_node(t_player **players, int *pl)
{
	if (*pl > 1)
	{
		(*players)->next = (t_player*)ft_memalloc(sizeof(t_player));
		(*players)->next->data = (header_t*)ft_memalloc(sizeof(header_t));
		(*players)->next->prev = *players;
		*players = (*players)->next;
		(*pl)--;
	}
}

static void	give_id(t_player *players, char **name, int n, int i)
{
	if (n >= 1)
	{
		players->id = i - (n * 2);
		players->fname = ft_strdup(name[0]);
	}
	else
	{
		players->fname = ft_strdup(name[0]);
		players->id = i;
	}
	players->arg_n = i;
}

static void	check_nflag(t_player *players, char *arg, int *n)
{
	if (ft_isdigit(arg[0]) == 1)
	{
		players->n_flag = ft_atoi2(arg);
		if (players->n_flag <= 0)
			players->n_flag = -1;
		(*n)++;
	}
	else
		exit(ft_printf("incorrect nflag format\n"));
}

int			str_ending(char *str, char *ending)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != ending[0])
		i--;
	if (str[i] == ending[0])
		return (ft_strcmp(&str[i], ending));
	return (1);
}

int			check_arg(int argc, char **argv, t_player *players)
{
	int			i;
	char		**name;
	int			n;
	int			pl;
	int			aflag;

	i = 1;
	n = 0;
	aflag = 0;
	pl = count_args(argv, argc);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			check_nflag(players, argv[i + 1], &n);
			i++;
		}
		else if (str_ending(argv[i], ".cor") == 0)
		{
			name = ft_strsplit(argv[i], '.');
			give_id(players, name, n, i);
			add_node(&players, &pl);
			free_arr(name);
		}
		else if (ft_strcmp(argv[i], "-a") == 0)
			aflag = 1;
		else
			exit(ft_printf("arg is not a '.cor' file\n"));
		i++;
	}
	ft_nflag(players);
	while (players->prev)
		players = players->prev;
	while (players->next)
	{
		ft_printf("Player %i is %s\n", players->id, players->fname);
		players = players->next;
	}
	ft_printf("Player %i is %s\n", players->id, players->fname);
	return (aflag);
}
