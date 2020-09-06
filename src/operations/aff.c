/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 16:36:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 18:21:02 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	aff takes a T_REG
**	and print the value on the standard ouput if the aflag is on
*/

int				aff(t_cursor *c, t_game *cw)
{
	int		val;

	ft_printf("lalalala\n");
	val = c->reg[c->ins->arg1];
	if (cw->aflag == 1)
		ft_printf("%c\n", (char)val);
	return (0);
}
