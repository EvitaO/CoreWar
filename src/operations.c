/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 15:32:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/04 15:32:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_argument(t_game *cw, int size, int pos)
{
	int 			p;
	int				i;
	int				ret;
	unsigned char	data[4];

	p = size;
	i = 0;
	while (i < size)
	{
		data[i] = cw->arena[get_pos(pos, p)];
		p--;
		i++;
	}
	ret = *(int*)data;
	return (ret);
}

void		collect_arguments(t_cursor *c, t_game *cw)
{
	int	pos;

	pos = get_pos(c->c_pos, g_op_tab[c->ins->op].octet);
	c->ins->arg1 = get_argument(cw, size_of_arg(*(c->ins), 0), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 0));
	c->ins->arg2 = get_argument(cw, size_of_arg(*(c->ins), 1), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 1));
	c->ins->arg3 = get_argument(cw, size_of_arg(*(c->ins), 2), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 2));
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 20, 0, "arg1 = %d, pos = %d", c->ins->arg1, pos);
		mvwprintw(cw->v->score, 21, 0, "arg2 = %d, pos = %d", c->ins->arg2, pos);
		mvwprintw(cw->v->score, 22, 0, "arg3 = %d, pos = %d", c->ins->arg3, pos);
		wrefresh(cw->v->score);
		sleep(SPEED);
	}
}

int		execute_operation(t_cursor *c, t_game *cw, t_ops op)
{
	int ret;
	int t = 0;

	ret = 1;
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, "check op-code");
		v_print_cursor(cw, c, 0);
	}
	if (c->op > 16 || c->op < 1)
		return (1);
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, "check-encoding-byte");
		v_print_cursor(cw, c, 0);
		sleep(SPEED);
	}
	t = encoding_byte(cw->arena[get_pos(c->c_pos, 1)], c->ins, &ret);
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, "check-encoding-byte2");
		v_print_cursor(cw, c, 0);
		sleep(SPEED);
	}
	if (!t)
		return (ret);
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, "getting arguments");
		v_print_cursor(cw, c, 0);
		sleep(SPEED);
	}
	collect_arguments(c, cw);
	if (!check_registries(*(c->ins)))
		return (ret);
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, "executing operation");
		v_print_cursor(cw, c, 0);
		sleep(SPEED);
	}
	op[c->ins->op](c, cw);
	return (ret);
}

void	get_operation(t_cursor *c, t_game *cw)
{
	t_instruction	*ins;

	c->op = cw->arena[c->c_pos];
	if (c->op > 16 || c->op < 1)
		c->wait = 0;
	else
	{
		ins = new_instruction();
		ins->op = cw->arena[c->c_pos];
		c->ins = ins;
		c->wait = g_op_tab[ins->op].cycles;
	}
}