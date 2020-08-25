/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:20:20 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/25 15:09:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	end_game(t_game *cw)
{
	if (cw)
		ft_putendl("Game over");
	exit(0);
}

void	check(t_game *cw)
{
	t_cursor *temp;

	temp = cw->c;
	cw->last_check = 1;
	while (temp)
	{
		if (temp->live > cw->cycles_to_die)
			kill_cursor(cw, temp->id);
		temp = temp->next;
	}
	if (cw->live_cnt >= NBR_LIVE || cw->checks_cnt >= MAX_CHECKS)
		cw->cycles_to_die -= CYCLE_DELTA;
	cw->live_cnt = 0;
	cw->die_cnt--;
	if (cw->die_cnt == 0)
	{
		cw->die_cnt = cw->cycles_to_die;
		cw->last_check = 0;
	}
}

void	game_loop(t_game *cw)
{
	t_cursor *temp;

	while (1)
	{
		temp = cw->c;
		if (cw->c == NULL || cw->cycles_to_die <= 0)
			end_game(cw);
		if ((cw->cycles_to_die > 0 && cw->last_check == 0) || cw->cycles_to_die < 1)
			check(cw);
		while (temp)
		{
			if (temp->c_pos != temp->p_pos)
				get_operation(temp, cw);
			temp->wait--;
			if (temp->wait <= 0)
				execute_operation(temp, cw);
			temp = temp->next;
		}
	}
}
