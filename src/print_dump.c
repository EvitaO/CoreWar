/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_dump.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 10:24:26 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/13 14:26:18 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			print_dump(t_game *cw)
{
	int		i;
	int		mod;

	i = 0;
	mod = cw->flag.mod;
	while (i < MEM_SIZE)
	{
		if (i % mod == 0 && i != 0)
			ft_printf("\n");
		if (i % mod == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", cw->arena[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
