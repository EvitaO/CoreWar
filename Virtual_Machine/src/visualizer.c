/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualizer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 02:51:19 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 15:30:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		get_hex_str(int num, char *str)
{
	char	*chars;

	chars = "0123456789abcdef";
	str[0] = chars[num / 16];
	str[1] = chars[num % 16];
}

void		init_info(t_visdata *info, t_player *p)
{
	info->i = 0;
	info->count = count_players(p);
	info->color = 2;
	info->size = p->data->prog_size;
	info->pos = 0;
}

void		v_print_arena2(t_visdata *info, t_game *cw, t_player *temp)
{
	if (info->size == 0)
	{
		info->pos = (MEM_SIZE / info->count) * (info->color - 1);
		wattron(cw->v->win, COLOR_PAIR(1));
	}
	if (info->pos == info->i && info->size <= 0)
	{
		temp = temp->next;
		info->color++;
		info->size = v_next_player(temp, cw->v->win, info->color);
	}
}

void		v_print_arena(t_game *cw, t_player *p)
{
	t_visdata	info;
	t_player	*temp;
	char		*pixel;

	init_info(&info, p);
	pixel = (char*)malloc(sizeof(char) * 4);
	pixel[3] = 0;
	pixel[2] = ' ';
	temp = p;
	wattron(cw->v->win, COLOR_PAIR(info.color));
	while (info.i < 4096)
	{
		v_print_arena2(&info, cw, temp);
		info.size--;
		get_hex_str(cw->arena[info.i], pixel);
		wprintw(cw->v->win, "%s", pixel);
		info.i++;
		wmove(cw->v->win, (info.i * 3) / WIDTH, (info.i * 3) % WIDTH);
	}
	free(pixel);
	wrefresh(cw->v->win);
}

t_visual	*v_start_visualizer(void)
{
	t_visual *new;

	new = (t_visual*)malloc(sizeof(t_visual));
	if (!new)
		return (NULL);
	initscr();
	new->win = newwin(HEIGHT, WIDTH, 0, 0);
	new->score = newwin(HEIGHT, 32, 0, WIDTH + 2);
	new->pos = 0;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	return (new);
}
