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
	int 			i;
	int 			multiply;
	unsigned int	ret;

	i = size;
	multiply = 1;
	ret = 0;
	while (i)
	{
		ret += cw->arena[get_pos(pos, i)] * multiply;
		if (multiply == 1)
			multiply = 16;
		else
			multiply *= multiply;
		i--;
	}
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
}

int		execute_operation(t_cursor *c, t_game *cw, t_ops op)
{
	int ret;

	ret = 0;
	if (c->op > 16)
		return (1);
	if (!encoding_byte(cw->arena[get_pos(c->c_pos, 1)], c->ins, &ret))
		return (ret);
	collect_arguments(c, cw);
	if (!check_registries(*(c->ins)))
		return (ret);
	op[c->ins->op](c, cw);
	free(c->ins);
	c->ins = NULL;
	return (ret);
}

void	get_operation(t_cursor *c, t_game *cw)
{
	t_instruction	*ins;

	c->op = cw->arena[c->c_pos];
	if (c->op > 16)
		c->wait = 0;
	else
	{
		ins = new_instruction();
		ins->op = cw->arena[c->c_pos];
		c->ins = ins;
		c->wait = g_op_tab[ins->op].cycles;
	}
}