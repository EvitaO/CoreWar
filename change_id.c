/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_id.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 17:00:24 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/02 19:08:03 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int          check(t_player **players)
{
	while ((*players)->prev)
	{
		if ((*players)->id == (*players)->prev->id + 1)
			*players = (*players)->prev;
		else
		{
			while ((*players)->prev)
				*players = (*players)->prev;
			return (0);
		}
	}
	if ((*players)->id == (*players)->next->id - 1)
		return (1);
	return (0);
}

static void          sort_players(t_player **players)
{
	int         i;
	t_player    *tmp;
	char        *name_tmp;

	i = 0;
	while ((*players)->next)
	{
		tmp = *players;
		*players = (*players)->next;
		if (tmp->id > (*players)->id)
		{
			name_tmp = ft_strdup(tmp->fname);
			tmp->fname = ft_strdup((*players)->fname);
			(*players)->fname = ft_strdup(name_tmp);
			i = tmp->id;
			tmp->id = (*players)->id;
			(*players)->id = i;
			i = tmp->arg_n;
			tmp->arg_n = (*players)->arg_n;
			(*players)->arg_n = i;
		}
	}
	//free(name_tmp);
	if (check(players) == 0)
		sort_players(players);
	else
		return ;
}

static void          increase_id(t_player *players, int n, int i)
{
	while (players->next)
	{
		if (players->n_flag == n)
			players->id = n;
		else if (players->id >= n && players->id < i)
			players->id = players->id + 1;
		players = players->next;
	}
	if (players->n_flag == n)
		players->id = n;
	else if (players->id >= n && players->id < i)
		players->id = players->id + 1;
}

static void          decrease_id(t_player *players, int n, int i)
{
	while (players->next)
	{
		if (players->n_flag == n)
			players->id = n;
		else if (players->id <= n && players->id > i)
			players->id = players->id - 1;
		players = players->next;
	}
	if (players->n_flag == n)
		players->id = n;
	else if (players->id <= n && players->id > i)
		players->id = players->id - 1;
}

void                ft_nflag(t_player *players)
{
	int         i;
	int         j;

	i = 0;
	j = 0;
	while (players->prev)
	{
		if (i <= 0 && players->n_flag > 0)
		{
			i = players->n_flag;
			j = players->id;
			if (i == players->id)
				return ;
		}
		players = players->prev;
	}
	if (i <= 0)
		i = players->n_flag;
	if (i <= 0)
		return;
	if (i > j)
		decrease_id(players, i, j);
	else
		increase_id(players, i, j);
	sort_players(&players);
}
