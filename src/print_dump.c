/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_dump.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 10:24:26 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/09 10:42:39 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			print_dump(t_game *cw)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0 && i != 0)
			ft_printf("\n");
		if (i % 32 == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", cw->arena[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
