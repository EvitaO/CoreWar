/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:20:20 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 16:38:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			end_game(t_game *cw)
{
	if (cw->c)
	{
		if (cw->c->ins)
			free(cw->c->ins);
		cw->c->ins = NULL;
	}
	return (cw->player_l_alive);
}

void		check(t_game *cw)
{
	t_cursor	*temp;

	temp = cw->c;
	cw->checks_cnt++;
	while (temp)
	{
		if (temp->live <= cw->cycles_cnt - cw->cycles_to_die || cw->cycles_to_die < 1)
		{
			if (cw->v != NULL)
			{
				v_print_cursor(cw, temp, 1);
				sleep(0);
			}
			kill_cursor(cw, &temp);
		}
		else
			temp = temp->next;
	}
	if (cw->live_cnt >= NBR_LIVE)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->checks_cnt = 0;
	}
	else if (cw->checks_cnt >= MAX_CHECKS)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->checks_cnt = 0;
	}
	cw->live_cnt = 0;
	if (cw->die_cnt < 1)
		cw->die_cnt = cw->cycles_to_die;
}

void		initialize_operations(t_ops *ops)
{
	(*ops)[1] = live;
	(*ops)[2] = ld;
	(*ops)[3] = st;
	(*ops)[4] = add;
	(*ops)[5] = sub;
	(*ops)[6] = and;
	(*ops)[7] = or;
	(*ops)[8] = xor;
	(*ops)[9] = zjmp;
	(*ops)[10] = ldi;
	(*ops)[11] = sti;
	(*ops)[12] = op_fork;
	(*ops)[13] = lld;
	(*ops)[14] = lldi;
	(*ops)[15] = lfork;
	(*ops)[16] = aff;
}

void		get_exec_op(t_game *cw, t_ops operations, t_cursor *temp)
{
	if (temp->op == -1)
	{
		temp->p_pos = temp->c_pos;
		get_operation(temp, cw);
	}
	temp->wait--;
	if (temp->wait <= 0 && temp->op >= 1 && temp->op <= 16)
	{
		if (temp->op != 9)
		{
			temp->c_pos = get_pos(temp->c_pos, \
			execute_operation(temp, cw, operations));
		}
		else
		{
			execute_operation(temp, cw, operations);
		}
		if (temp->ins)
		{
			free(temp->ins);
			temp->ins = NULL;
		}
		if (cw->v != NULL)
		{
			wmove(cw->v->win, temp->c_pos / WIDTH, temp->c_pos % WIDTH);
			v_print_pixel(cw, temp->c_pos, 5);
			usleep(80000);
			wrefresh(cw->v->win);
		}
		temp->op = -1;
	}
	else if (temp->wait <= 0)
	{
		temp->c_pos = (temp->c_pos + 1) % MEM_SIZE;
		temp->op = -1;
		if (cw->v != NULL)
		{
			wmove(cw->v->win, temp->c_pos / WIDTH, temp->c_pos % WIDTH);
			v_print_pixel(cw, temp->c_pos, 1);
			wrefresh(cw->v->win);
		}
	}
}

int			game_loop(t_game *cw)
{
	t_cursor	*temp;
	t_ops		operations;

	initialize_operations(&operations);
	while (1)
	{
		cw->cycles_cnt++;
		if (cw->die_cnt == 0 || cw->cycles_to_die < 1)
			check(cw);
		cw->die_cnt--;
		if (cw->c == NULL)
			return (end_game(cw));
		temp = cw->c;
		if (cw->v != NULL)
			v_print_score(cw);
		while (temp)
		{
			get_exec_op(cw, operations, temp);
			temp = temp->next;
		}
		if (cw->flag.dump_flag > 0 && cw->cycles_cnt == cw->flag.dump_flag)
			exit(print_dump(cw));
	}
}
