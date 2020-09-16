/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 11:19:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 22:01:03 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		get_pos(int position, int distance)
{
	int new_pos;

	new_pos = position + distance;
	while (new_pos < 0)
		new_pos += MEM_SIZE;
	return (new_pos % MEM_SIZE);
}

void	print_instruction_data(t_cursor *c)
{
	t_instruction ins;

	ins = *(c->ins);
	ft_printf("cursor%5i | ", c->pos);
	ft_printf("%s ", g_op_tab[ins.op].name);
	if (ins.arg_type[0] == T_REG)
		ft_printf("r");
	if (ins.arg_type[0])
		ft_printf("%i ", ins.arg1);
	if (ins.arg_type[1] == T_REG)
		ft_printf("r");
	if (ins.arg_type[1])
		ft_printf("%i ", ins.arg2);
	if (ins.arg_type[2] == T_REG)
		ft_printf("r");
	if (ins.arg_type[2])
		ft_printf("%i ", ins.arg3);
	if (ins.op == 9)
	{
		if (c->carry == 1)
			ft_printf("OK");
		else
			ft_printf("FAILED");
	}
	ft_printf("\n");
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
