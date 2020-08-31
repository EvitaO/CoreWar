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

int		end_game(t_game *cw)
{
	return (cw->player_l_alive);
}

void	check(t_game *cw)
{
	t_cursor *temp;

	// ft_printf("\nThe check\n");
	temp = cw->c;
	cw->checks_cnt++;
	while (temp)
	{
		if (temp->live < cw->cycles_cnt - cw->cycles_to_die)
			kill_cursor(cw, temp->id);
		temp = temp->next;
	}
	if (cw->live_cnt >= NBR_LIVE || cw->checks_cnt >= MAX_CHECKS)
		cw->cycles_to_die -= CYCLE_DELTA;
	cw->live_cnt = 0;
	if (cw->die_cnt < 1)
		cw->die_cnt = cw->cycles_to_die;
	// print_game_data(cw);
}

void		initialize_operations(t_ops *ops)
{
	(*ops)[1] = live;
	(*ops)[2] = live;
	(*ops)[3] = live;
	(*ops)[4] = live;
	(*ops)[5] = live;
	(*ops)[6] = live;
	(*ops)[7] = live;
	(*ops)[8] = live;
	(*ops)[9] = live;
	(*ops)[10] = live;
	(*ops)[11] = live;
	(*ops)[12] = live;
	(*ops)[13] = live;
	(*ops)[14] = live;
	(*ops)[15] = live;
	(*ops)[16] = live;
}

int		game_loop(t_game *cw)
{
	t_cursor	*temp;
	t_ops		operations;
	int i = 1;
	int j;

	initialize_operations(&operations);
	while (1)
	{
		// print_game_data(cw);
		//sleep(1);
		cw->cycles_cnt++;
		cw->die_cnt--;
		temp = cw->c;
		// ft_printf("checking for check\n");
		if ((cw->cycles_to_die > 0 && cw->die_cnt == 0) || cw->cycles_to_die < 1)
			check(cw);
		// ft_printf("checking for game over\n");
		if (cw->c == NULL || cw->cycles_to_die <= 0)
			return(end_game(cw));
		// ft_printf("\nchecking each cursor:\n");
		j = 1;
		while (temp)
		{
			// ft_printf("cursor %i\n", j);
			if (temp->op == -1)
			{
				temp->p_pos = temp->c_pos;
				get_operation(temp, cw);
			}
			temp->wait--;
			if (temp->wait <= 0)
			{
				// ft_printf("Execute operation\n");
				temp->c_pos = get_pos(temp->c_pos, execute_operation(temp, cw, operations));
				// print_cursor_data(cw);
				temp->op = -1;
			}
			temp = temp->next;
			j++;
		}
		i++;
	}
}