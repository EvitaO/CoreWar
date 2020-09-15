/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:39:26 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 14:17:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				or(t_cursor *c, t_game *cw)
{
	int arg1;
	int arg2;

	if (c->ins->arg_type[0] == T_IND)
		arg1 = get_argument(cw, 4, get_pos(c->c_pos, c->ins->arg1 % IDX_MOD));
	else if (c->ins->arg_type[0] == T_DIR)
		arg1 = c->ins->arg1;
	else
		arg1 = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_IND)
		arg2 = get_argument(cw, 4, get_pos(c->c_pos, c->ins->arg2 % IDX_MOD));
	else if (c->ins->arg_type[1] == T_DIR)
		arg2 = c->ins->arg2;
	else
		arg2 = c->reg[c->ins->arg2];
	c->reg[c->ins->arg3] = (arg1 | arg2);
	//ft_printf("or:	arg1 %i=%i\t\targ2	%i=%i	r%i\n", arg1, c->ins->arg1, arg2, c->ins->arg2, c->ins->arg3);
	if (c->reg[c->ins->arg3] != 0)
	{
		c->carry = 0;
		return (1);
	}
	else
		c->carry = 1;
	return (0);
}
