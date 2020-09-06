/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 16:36:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/06 16:48:17 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*need to add aflag */

int				aff(t_cursor *c, t_game *cw)
{
	int		val;

	ft_printf("lalalala\n");
	val = c->reg[c->ins->arg1];
	if (cw)
		ft_printf("%c\n", (char)val);
	return (0);
}
