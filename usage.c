/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   usage.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 17:03:53 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 17:14:02 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		usage(void)
{
	ft_printf("Usage: ./corewar [[-n number] champion1.cor] ...\n");
	ft_printf("		Possible Flags:\n");
	ft_printf("			-u	: Outputs this usage message\n");
	ft_printf("			-d N	: Dumps memory after N cycles then exits\n");
	exit(1);
}
