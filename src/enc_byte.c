/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enc_byte.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 11:19:50 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/25 13:12:46 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		size_of_arg(t_instruction ins)
{
	int	ret;

	ret = 3;
	if (ins.a1_type == T_DIR)
		ret += DIR_SIZE - 1;
	else if (ins.a1_type == T_IND)
		ret += IND_SIZE - 1;
	if (ins.a2_type == T_DIR)
		ret += DIR_SIZE - 1;
	else if (ins.a2_type == T_IND)
		ret += IND_SIZE - 1;
	if (ins.a3_type == T_DIR)
		ret += DIR_SIZE - 1;
	else if (ins.a3_type == T_IND)
		ret += IND_SIZE - 1;
	return (ret);
}

int		check_enc_byte(t_instruction ins)
{
	if (ins.op > 16)
		return (0);
	if (ins.a1_type != g_op_tab[ins.op - 1].arg_type[0])
		return (0);
	if (ins.a2_type != g_op_tab[ins.op - 1].arg_type[1])
		return (0);
	if (ins.a3_type != g_op_tab[ins.op - 1].arg_type[2])
		return (0);
	return (1);
}

int		encoding_byte(unsigned char data, t_instruction *ins, int *ret)
{
	ins->a1_type = (data >> 6) & 3;
	ins->a2_type = (data >> 4) & 3;
	ins->a3_type = (data >> 2) & 3;
	*ret = size_of_arg(*ins);
	if (!check_enc_byte(*ins) || data & 3)
		return (0);
	return (1);
}