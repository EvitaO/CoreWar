/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 15:53:15 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/30 16:02:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		live(t_cursor *c, t_game *cw)
{
	cw->live_cnt++;
	c->live = cw->cycles_cnt;
	if (-(c->ins->arg1) == c->reg[0])
		cw->player_l_alive = c->ins->arg1;
	else
		return (0);
	return (1);
}