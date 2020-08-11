/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 19:30:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/10 20:01:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void        add_node(t_player **players)
{
	(*players)->next = (t_player*)ft_memalloc(sizeof(t_player));
	(*players)->next->data = (header_t*)ft_memalloc(sizeof(header_t));
	(*players)->next->prev = *players;
	*players = (*players)->next;
}

static void        give_id(t_player *players, char **name, int n , int i)
{
	if (n == 1)
	{
		players->id = i - 2;
		players->fname = ft_strdup(name[0]);
	}
	else
	{
		players->fname = ft_strdup(name[0]);
		players->id = i;
	}
	players->arg_n = i;
}

static void  check_nflag(t_player *players, char *arg, int *n)
{
	if (ft_isdigit(arg[0]) == 1)
	{
		players->n_flag = ft_atoi2(arg);
		if (players->n_flag <= 0)
			players->n_flag = -1;
		*n = 1;
	}
	else
		exit(ft_printf("incorrect nflag format\n"));
}

void		free_arr(char **name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		free(name[i]);
		i++;
	}
	free(name);
}

void        check_arg(int argc, char **argv, t_player *players)
{
	int         i;
	char        *file;
	char        **name;
	int         n;
	int         pl;

	i = 1;
	n = 0;
	pl = argc - 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			check_nflag(players, argv[i + 1], &n);
			i++;
			pl = pl - 2;
		}
		else
		{
			file = ft_strstr(argv[i], ".cor");
			if (file != NULL)
			{
				name = ft_strsplit(argv[i], '.');
				give_id(players, name, n, i);
				if (i + 1 <= pl)
					add_node(&players);
				free_arr(name);
			}
			else
				ft_printf("arg is not a '.cor' file\n");
		}
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
}
