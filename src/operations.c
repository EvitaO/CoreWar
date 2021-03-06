/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 15:32:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 12:18:05 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_argument(t_game *cw, int size, int pos)
{
	int				p;
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
	if (size == 2)
		ret = *(short*)data;
	if (size == 1)
		ret = *(char*)data;
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
		mvwprintw(cw->v->score, 20, 0, "arg1 = %d, pos = %d", \
		c->ins->arg1, pos);
		mvwprintw(cw->v->score, 21, 0, "arg2 = %d, pos = %d", \
		c->ins->arg2, pos);
		mvwprintw(cw->v->score, 22, 0, "arg3 = %d, pos = %d", \
		c->ins->arg3, pos);
		wrefresh(cw->v->score);
		usleep(2);
	}
}

void		exec_vis(t_game *cw, t_cursor *c, char *str)
{
	if (!c)
	if (ft_strcmp(str, "check op-code") == 0)
	{
		wclear(cw->v->score);
		mvwprintw(cw->v->score, 7, 0, "check op-code");
		v_print_score(cw);
		// v_print_cursor(cw, c, 0);
	}
	if (cw->v != NULL)
	{
		mvwprintw(cw->v->score, 7, 0, str);
		// v_print_cursor(cw, c, 0);
		usleep(2);
	}
}

int			execute_operation(t_cursor *c, t_game *cw, t_ops op)
{
	int	ret;
	int	t;

	ret = 1;
	t = 0;
	if (cw->v != NULL)
		exec_vis(cw, c, "check op-code");
	if (c->op > 16 || c->op < 1)
		return (1);
	if (cw->v != NULL)
		exec_vis(cw, c, "check-encoding-byte");
	t = encoding_byte(cw->arena[get_pos(c->c_pos, 1)], c->ins, &ret);
	if (cw->v != NULL)
		exec_vis(cw, c, "check-encoding-byte2");
	if (!t)
		return (ret);
	if (cw->v != NULL)
		exec_vis(cw, c, "getting arguments");
	collect_arguments(c, cw);
	if (!check_registries(*(c->ins)))
		return (ret);
	if (cw->v != NULL)
		exec_vis(cw, c, "executing operation");
	//if (cw->cycles_cnt <= 218 && cw->cycles_cnt >= 217)
	// print_instruction_data(c);
	// ft_printf("\t\t%i\n", cw->cycles_cnt);
	op[c->ins->op](c, cw);
	return (ret);
}

void		get_operation(t_cursor *c, t_game *cw)
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
