/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 16:36:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/28 16:55:24 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			aff(t_cursor *c, t_game *cw)
{
	ft_printf("%c", (char)c->ins->arg1);
}
