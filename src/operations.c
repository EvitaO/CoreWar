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
	//ft_printf("i:%i, ret:%i, multi:%i\n", i, ret, multiply);
	while (i)
	{
		ret += cw->arena[get_pos(pos, i)] * multiply;
		if (multiply == 1)
			multiply = 16;
		else
			multiply *= multiply;
		i--;
		//ft_printf("i:%i, ret:%i, multi:%i\n", i, ret, multiply);
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

	ret = 1;
	if (c->op > 16 || c->op < 1)
		return (1);
	//ft_printf("Checking encoding byte\n");
	if (!encoding_byte(cw->arena[get_pos(c->c_pos, 1)], c->ins, &ret))
		return (ret);
	//ft_printf("Collect arguments\n");
	collect_arguments(c, cw);
	//ft_printf("Check registries\n");
	if (!check_registries(*(c->ins)))
		return (ret);
	//ft_printf("Execute operation\n");
	// ft_printf("cursor->reg1 = %i\n", c->reg[0]);
	// print_instruction_data(*(c->ins));
	op[c->ins->op](c, cw);
	free(c->ins);
	c->ins = NULL;
	return (ret);
}

void	get_operation(t_cursor *c, t_game *cw)
{
	t_instruction	*ins;

	// ft_printf("Getting operation\n");
	// ft_printf("stats:\n");
	// ft_printf("pos:%i\n", c->c_pos);
	c->op = cw->arena[c->c_pos];
	// ft_printf("op:%i\n", c->op);
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