/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_visualizer.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 11:42:56 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:00:02 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VISUALIZER_H
# define VM_VISUALIZER_H

# include "vm.h"
# include <ncurses.h>
# include <curses.h>

# define HEIGHT 64
# define WIDTH 192

/*
** change to 'SPEED 0' to run the program in real time
*/
# define SPEED 1

typedef struct			s_visual
{
	WINDOW	*win;
	WINDOW	*score;
	int		pos;
}						t_visual;

typedef struct			s_visdata
{
	int			size;
	int			color;
	int			pos;
	int			count;
	int			i;
}						t_visdata;

/*
**		visualizer
*/
t_visual				*v_start_visualizer(void);
void					v_print_arena(t_game *cw, t_player *p);
void					v_print_arena2(t_visdata *info, t_game *cw, \
						t_player *temp);
void					v_print_score(t_game *cw);
void					v_print_pixel(t_game *cw, int i, int color);
void					v_print_cursor(t_game *cw, t_cursor *c, int mode);
int						v_next_player(t_player *p, WINDOW *win, int color);

#endif
