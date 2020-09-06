/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 18:07:08 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/06 18:47:04 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**  ldi takes 3 arguments
**  arg1    T_REG/T_DIR/T_IND
**  arg2    T_REG/T_DIR
**  arg3    T_REG
**  ldi reads 4 bytes from the address current_pos + ((arg1 + arg2) % IDX_MOD)
**  and saves the result to arg3
**  if arg1 is a T_IND the 4 bytes are read from current_pos + (arg1 % IDX_MOD)
**  if the value of arg3 != 0, carry is set to 0 else cary is set to 1
*/

/*
**  lldi is the same as ldi but without % IDX_MOD
**  if arg1 == T_IND then the % IDX_MOD is still performed
*/

static int      read_bytes(t_game *cw, int address, int size)
{
    //function for ldi and lldi to read bytes and return value of those bytes
    return (1);
}

int		        ldi(t_cursor *c, t_game *cw)
{
    int     address;

    if (c->ins->arg_type[0] == T_REG)
        c->ins->arg1 = c->reg[c->ins->arg1];
    else if (c->ins->arg_type[0] == T_IND)
        address = c->c_pos + (c->ins->arg1 % IDX_MOD);
    if (c->ins->arg_type[1] == T_REG)
        c->ins->arg2 = c->reg[c->ins->arg2];
    if (c->ins->arg_type[0] != T_IND)
        address = c->c_pos + ((c->ins->arg1 + c->ins->arg2) % IDX_MOD);
    c->reg[c->ins->arg3] = read_bytes(cw, address, 4);
    if (c->reg[c->ins->arg3] == 0)
        c->carry = 1;
    else
        c->carry = 0;
}

int		        lldi(t_cursor *c, t_game *cw)
{
    int     address;

    if (c->ins->arg_type[0] == T_REG)
        c->ins->arg1 = c->reg[c->ins->arg1];
    else if (c->ins->arg_type[0] == T_IND)
        address = c->c_pos + (c->ins->arg1 % IDX_MOD);
    if (c->ins->arg_type[1] == T_REG)
        c->ins->arg2 = c->reg[c->ins->arg2];
    if (c->ins->arg_type[0] != T_IND)
        address = c->c_pos + (c->ins->arg1 + c->ins->arg2);
    c->reg[c->ins->arg3] = read_bytes(cw, address, 4);
    if (c->reg[c->ins->arg3] == 0)
        c->carry = 1;
    else
        c->carry = 0;
}
