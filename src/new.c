/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:18:49 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 11:18:49 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

// t_game		*new_game(int players)
// {
// 	t_game *new;

// 	new = (t_game*)malloc(sizeof(t_game));
// 	if (!new)
// 		exit(0);
// 	new->players = players;
// 	new->cycles = 0;
// 	new->live = 0;
// 	new->die_cycle = 1536;
// 	new->check_count = 0;
// 	new->c = NULL;
// 	new->arena = new_arena();
// 	return (new);
// }

// t_cursor	*new_cursor(int	id, int pos, int c)
// {
// 	t_cursor	*new;
// 	int			i;

// 	i = 1;
// 	new = (t_cursor*)malloc(sizeof(t_cursor));
// 	if (!new)
// 		exit(0);
// 	new->id = id;
// 	new->carry = 0;
// 	new->op = 0;
// 	new->live = 0;
// 	new->wait = 0;
// 	new->c_pos = pos;
// 	new->p_pos = -1;
// 	new->jump = 0;
// 	new->reg[0] = -c;
// 	while (i < REG_NUMBER)
// 	{
// 		new->reg[i] = 0;
// 		i++;
// 	}
// 	return (new);
// }

// unsigned char	*new_arena(void)
// {
// 	unsigned char	*arena;
// 	int				i;

// 	i = 0;
// 	arena = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
// 	if (!arena)
// 		exit(0);
// 	while (i < MEM_SIZE)
// 	{
// 		arena[i] = 0;
// 		i++;
// 	}
// 	return (arena);
// }

t_instruction		*new_instruction(void)
{
	t_instruction *new;

	new = (t_instruction*)malloc(sizeof(t_instruction));
	if (!new)
		exit(0);
	new->arg_type[0] = 0;
	new->arg_type[1] = 0;
	new->arg_type[2] = 0;
	new->arg1 = 0;
	new->arg2 = 0;
	new->arg3 = 0;
	new->op = 0;
	return (new);
}
