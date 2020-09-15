/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:02:41 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:35 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	write_to_memory(t_game *cw, int arg, int size, int pos)
{
	unsigned char	mask;
	int				shift;
	int				i;
	int				w_pos;

	i = 0;
	mask = 255;
	shift = 24;
	w_pos = pos;
	while (i < size)
	{
		cw->arena[w_pos] = (arg >> shift) & mask;
		if (cw->v != NULL)
			v_print_pixel(cw, w_pos, 4);
		shift -= 8;
		i++;
		w_pos = get_pos(w_pos, 1);
	}
}
