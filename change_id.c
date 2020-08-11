/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_id.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 17:00:24 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/11 14:46:32 by anonymous     ########   odam.nl         */
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

static int			find_n(t_player **players, int old_n, int max_pl)
{
	while ((*players)->prev)
	{
		if ((*players)->n_flag > 0 && (*players)->arg_n != old_n)
		{
			if ((*players)->n_flag > max_pl)
				(*players)->n_flag = -1;
			else
				return ((*players)->n_flag - 1);
		}
		*players = (*players)->prev;
	}
	if ((*players)->n_flag > 0 && (*players)->arg_n != old_n)
	{
		if ((*players)->n_flag > max_pl)
			(*players)->n_flag = -1;
		else
			return ((*players)->n_flag - 1);
	}
	return (-1);
}

static int			search_in_arr(int *arr, int num, int max_pl)
{
	int		i;

	i = 0;
	while (i < max_pl)
	{
		if (arr[i] == num)
			return (i + 1);
		i++;
	}
	return (-2);
}

static void			proces_nflag(t_player *players, int n, int max_pl)
{
	int			arr[max_pl];
	int			i;
	int			cnt;

	i = 0;
	while (i <= max_pl)
	{
		arr[i] = -1;
		i++;
	}
	arr[n] = players->arg_n;
	n = find_n(&players, players->arg_n, max_pl);
	while (n != -1)
	{
		if (arr[n] == -1)
			arr[n] = players->arg_n;
		else
			exit(ft_printf("same n_flag used twice\n"));
		n = find_n(&players, players->arg_n, max_pl);
	}
	if (n == -1)
	{
		while (players->next)
		{
			if (players->n_flag <= 0)
			{
				i = players->id - 1;
				while (arr[i] != -1 && i < max_pl)
					i++;
				if (i == max_pl)
				{
					i--;
					while (arr[i] != -1)
						i--;
				}
				if (arr[i] == -1)
					arr[i] = players->arg_n;
			}
			players = players->next;
		}
		if (players->n_flag <= 0)
		{
			i = players->id - 1;
			while (arr[i] != -1)
				i++;
			if (i == max_pl)
			{
				i--;
				while (arr[i] != -1)
					i--;
			}
			if (arr[i] == -1)
				arr[i] = players->arg_n;
		}
	}
	while (players->next)
		players = players->next;
	while (players->prev)
	{
		players->id = search_in_arr(arr, players->arg_n, max_pl);
		players = players->prev;
	}
	players->id = search_in_arr(arr, players->arg_n, max_pl);
}

void                ft_nflag(t_player *players)
{
	int			i;
	int			cnt;

	cnt = count_players(players);
	i = find_n(&players, -1, cnt);
	if (i < 0)
		return;
	proces_nflag(players, i, cnt);
	sort_players(&players);
}
