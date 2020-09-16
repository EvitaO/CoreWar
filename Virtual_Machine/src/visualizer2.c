/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualizer2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 13:51:22 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:51:06 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			v_next_player(t_player *p, WINDOW *win, int color)
{
	if (!p)
	{
		wattron(win, COLOR_PAIR(1));
		return (0);
	}
	wattron(win, COLOR_PAIR(color));
	return (p->data->prog_size);
}

void		v_print_cursor(t_game *cw, t_cursor *c, int mode)
{
	int i;

	i = 0;
	if (mode == 1)
		i = 10;
	wmove(cw->v->score, 8 + i, 0);
	wprintw(cw->v->score, "id:\t\t%d", c->id);
	wmove(cw->v->score, 9 + i, 0);
	wprintw(cw->v->score, "pos:\t\t%d", c->c_pos);
	wmove(cw->v->score, 10 + i, 0);
	wprintw(cw->v->score, "op:\t\t%d", c->op);
	if (c->ins)
	{
		wmove(cw->v->score, 11 + i, 0);
		wprintw(cw->v->score, "ins:\t\t%d", c->ins->op);
		mvwprintw(cw->v->score, 12 + 1, 0, "arg1 = t:%d, v:%d", \
		c->ins->arg_type[0], c->ins->arg1);
		mvwprintw(cw->v->score, 13 + 1, 0, "arg1 = t:%d, v:%d", \
		c->ins->arg_type[1], c->ins->arg2);
		mvwprintw(cw->v->score, 14 + 1, 0, "arg1 = t:%d, v:%d", \
		c->ins->arg_type[2], c->ins->arg3);
	}
	wrefresh(cw->v->score);
}

void		v_print_pixel(t_game *cw, int i, int color)
{
	char	*chars;
	char	pixel[3];
	int		num;

	chars = "0123456789abcdef";
	num = cw->arena[i];
	pixel[0] = chars[num / 16];
	pixel[1] = chars[num % 16];
	pixel[2] = 0;
	i *= 3;
	wmove(cw->v->win, i / WIDTH, i % WIDTH);
	wattron(cw->v->win, COLOR_PAIR(color));
	wattron(cw->v->win, A_REVERSE);
	wprintw(cw->v->win, "%s", pixel);
	wrefresh(cw->v->win);
	usleep(10000);
	wattroff(cw->v->win, A_REVERSE);
	wmove(cw->v->win, i / WIDTH, i % WIDTH);
	wprintw(cw->v->win, "%s", pixel);
	wrefresh(cw->v->win);
}

void		v_print_score(t_game *cw)
{
	wmove(cw->v->score, 0, 0);
	wprintw(cw->v->score, "Cycles:\t\t\t%d", cw->cycles_cnt);
	wmove(cw->v->score, 1, 0);
	wprintw(cw->v->score, "Player last live:\t%d", cw->player_l_alive);
	wmove(cw->v->score, 2, 0);
	wprintw(cw->v->score, "Live count:\t\t%d", cw->live_cnt);
	wmove(cw->v->score, 3, 0);
	wprintw(cw->v->score, "Cycles to die:\t\t%d", cw->cycles_to_die);
	wmove(cw->v->score, 4, 0);
	wprintw(cw->v->score, "Countdown to check:\t    ");
	wmove(cw->v->score, 4, 0);
	wprintw(cw->v->score, "Countdown to check:\t%d", cw->die_cnt);
	wmove(cw->v->score, 5, 0);
	wprintw(cw->v->score, "Check count:\t\t%4d", cw->checks_cnt);
	wrefresh(cw->v->score);
}
