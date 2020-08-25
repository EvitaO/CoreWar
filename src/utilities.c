/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 11:19:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/18 13:09:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_pos(int position, int distance)
{
	int new_pos;

	new_pos = position + distance;
	if (new_pos < 0)
		return (MEM_SIZE - new_pos);
	return (new_pos % MEM_SIZE);
}