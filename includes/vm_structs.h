/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_structs.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 13:32:50 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/07 14:04:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

# include "vm.h"

typedef struct			s_flag
{
	int					aflag;
	int					vflag;
}						t_flag;

typedef struct			s_player
{
	int					id;
	char				*fname;
	header_t			*data;
	unsigned char		*code;
	int					n_flag;
	int					arg_n;
	int					cursor;
	struct s_player		*prev;
	struct s_player		*next;
}						t_player;

typedef struct			s_op
{
	char				*name;
	int					arg_cnt;
	char				arg_type[3];
	int					id;
	int					cycles;
	char				*description;
	int					octet;
	int					label_size;
}						t_op;

extern t_op				g_op_tab[17];

typedef struct			s_game
{
	int					player_l_alive;
	int					cycles_cnt;
	int					live_cnt;
	int					cycles_to_die;
	int					die_cnt;
	int					checks_cnt;
	int					players;
	t_flag				flag;
	unsigned char		arena[MEM_SIZE + 1];
	struct s_op			op_tab[16];
	struct s_cursor		*c;
	struct s_visual		*v;
}						t_game;

typedef struct			s_cursor
{
	int	 				id;
	int 				carry;
	int					c_pos;
	int					p_pos;
	int					op;
	int					live;
	int					wait;
	int					jump;
	int					reg[REG_NUMBER + 1];
	struct s_instruction*ins;
	struct s_cursor		*next;
	struct s_cursor		*prev;
}						t_cursor;

typedef struct			s_instruction
{
	int op;
	int	arg1;
	int arg2;
	int arg3;
	int	arg_type[3];
}						t_instruction;

typedef int		(*t_ops[17])(t_cursor *c, t_game *cw);

#endif