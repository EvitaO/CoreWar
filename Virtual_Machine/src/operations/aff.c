/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 16:36:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 15:41:04 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

/*
**	aff takes a T_REG
**	and print the value on the standard ouput if the aflag is on
*/

int				aff(t_cursor *c, t_game *cw)
{
	int		val;

	if (c->ins->arg_type[0] == T_REG)
	{
		val = c->reg[c->ins->arg1] % 256;
		if (cw->flag.aflag == 1)
			ft_printf("Aff:	%c\n", (char)val);
	}
	return (0);
}
