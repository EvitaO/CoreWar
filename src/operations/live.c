/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 15:53:15 by anonymous     #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/09/15 11:42:15 by anonymous     ########   odam.nl         */
=======
/*   Updated: 2020/09/15 12:39:28 by eovertoo      ########   odam.nl         */
>>>>>>> c9d963fa37892b600f8245df3f68881ed6a05fb6
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		live(t_cursor *c, t_game *cw)
{
	cw->live_cnt++;
	c->live = cw->cycles_cnt;
	if (c->ins->arg1 == c->reg[1] && \
		(-(c->ins->arg1) > 0 && -(c->ins->arg1) <= cw->players))
	{
		//ft_printf("live %i\n", c->ins->arg1);
		cw->player_l_alive = -(c->ins->arg1);
	}
	else
		return (0);
	if (cw->v != NULL)
		wclear(cw->v->score);
	return (1);
}
