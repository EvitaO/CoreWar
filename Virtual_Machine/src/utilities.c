/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 11:19:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 15:30:19 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		get_pos(int position, int distance)
{
	int new_pos;

	new_pos = position + distance;
	if (new_pos < 0)
		return (MEM_SIZE + new_pos);
	return (new_pos % MEM_SIZE);
}

void	print_game_data(t_game *data)
{
	ft_printf("---GAME DATA---\n");
	ft_printf("Player last alive: %i\n", data->player_l_alive);
	ft_printf("Cycles count:\t   %i\n", data->cycles_cnt);
	ft_printf("Live count:\t   %i\n", data->live_cnt);
	ft_printf("Cycles to die:\t   %i\n", data->cycles_to_die);
	ft_printf("Die countdown:\t   %i\n", data->die_cnt);
	ft_printf("Checks count:\t   %i\n", data->checks_cnt);
	print_cursor_data(data);
}

void	print_cursor_data(t_game *data)
{
	t_cursor *temp;

	temp = data->c;
	ft_printf("---CURSOR DATA---\n");
	while (temp)
	{
		ft_printf("id:%i, c_pos:%i, live:%i, op:%i, wait:%i\n", \
		temp->id, temp->c_pos, temp->live, temp->op, temp->wait);
		temp = temp->next;
	}
}

void	print_instruction_data(t_instruction ins)
{
	ft_printf("Executing: %i -> %s\n", ins.op, g_op_tab[ins.op].name);
	ft_printf("arg1_type = %i, arg1 = %i\n", ins.arg_type[0], ins.arg1);
	ft_printf("arg2_type = %i, arg2 = %i\n", ins.arg_type[1], ins.arg2);
	ft_printf("arg3_type = %i, arg3 = %i\n", ins.arg_type[2], ins.arg3);
	sleep(2);
}

char	*get_winner(t_player *players, int id)
{
	t_player *temp;

	temp = players;
	while (temp)
	{
		if (temp->id == id)
			return (temp->data->prog_name);
		temp = temp->next;
	}
	return (NULL);
}
