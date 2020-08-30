/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:20:20 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 11:20:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	end_game(t_game *cw)
{
	if (cw)
		ft_putendl("Game Over");
	exit(0);
}

void	check(t_game *cw)
{
	t_cursor *temp;

	temp = cw->c;
	cw->last_check = 1;
	while (temp)
	{
		if (temp->live < cw->cycles_cnt - cw->cycles_to_die)
			kill_cursor(cw, temp->id);
		temp = temp->next;
	}
	if (cw->live_cnt >= NBR_LIVE || cw->checks_cnt >= MAX_CHECKS)
		cw->cycles_to_die -= CYCLE_DELTA;
	cw->live_cnt = 0;
	cw->die_cnt--;
	if (cw->die_cnt < 1)
		cw->die_cnt = cw->cycles_to_die;
}

int			live(t_cursor *c, t_game *cw)
{
	if (c || cw)
		return (1);
	return (0);
}

void		initialize_operations(t_ops *ops)
{
	(*ops)[1] = live;
	// (*ops)[2] = ld;
	// (*ops)[3] = st;
	// (*ops)[4] = add;
	// (*ops)[5] = sub;
	// (*ops)[6] = and;
	// (*ops)[7] = or;
	// (*ops)[8] = xor;
	// (*ops)[9] = zjmp;
	// (*ops)[10] = ldi;
	// (*ops)[11] = sti;
	//(*ops)[12] = fork;
	// (*ops)[13] = lld;
	// (*ops)[14] = lldi;
	// (*ops)[15] = lfork;
	// (*ops)[16] = aff;
}

void	game_loop(t_game *cw)
{
	t_cursor	*temp;
	t_ops		operations;

	initialize_operations(&operations);
	while (1)
	{
		temp = cw->c;
		if ((cw->cycles_to_die > 0 && cw->die_cnt == 0) || cw->cycles_to_die < 1)
			check(cw);
		if (cw->c == NULL || cw->cycles_to_die <= 0)
			end_game(cw);
		while (temp)
		{
			if (temp->c_pos != temp->p_pos)
			{
				temp->p_pos = temp->c_pos;
				get_operation(temp, cw);
			}
			temp->wait--;
			if (temp->wait <= 0)
				temp->c_pos = get_pos(temp->c_pos, execute_operation(temp, cw, operations));
			temp = temp->next;
		}
	}
}