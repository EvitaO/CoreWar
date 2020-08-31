/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:28:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 11:28:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	kill_cursor(t_game *cw, int id)
{
	t_cursor *temp;
	// int i = 0;

	temp = cw->c;
	while (temp)
	{
		// ft_printf("i = %i\n", i);
		if (temp->id == id)
		{
			if (temp->prev)
				temp->prev->next = temp->next;
			else
				cw->c = temp->next;
			free(temp);
			return ;
		}
		// i++;
		temp = temp->next;
	}
}