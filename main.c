/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:15:00 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/01 20:54:18 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int       main(int argc, char **argv)
{
    t_player    *players;

    players = (t_player*)ft_memalloc(sizeof(t_player));
    if (argc < 2)
        ft_printf("Not enough arguments\n");
    check_arg(argc, argv, players);
    read_args(argv, players);
    return (0);
}