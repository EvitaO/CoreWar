/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 09:40:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/25 15:05:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

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
	int					carry;
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
	int					last_check;
	int					players;
	unsigned char		arena[MEM_SIZE + 1];
	struct s_op			op_tab[16];
	struct s_cursor		*c;
}						t_game;

typedef struct			s_cursor
{
	int					id;
	int					carry;
	int					c_pos;
	int					p_pos;
	int					op;
	int					live;
	int					wait;
	int					jump;
	int					reg[REG_NUMBER];
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
	int a1_type;
	int a2_type;
	int a3_type;
}						t_instruction;

/*
**      input saving functions
*/
void					read_args(char **argv, t_player *players);
void					check_arg(int argc, char **argv, t_player *players);
char					*itoa_base(unsigned long long nbr, int base);
int						ft_atoi2(const char *str);
char					*str_rev_by_2(char *str);
int						count_args(char **argv, int argc);
void					usage(void);

/*
**      process n_flag
*/
void					ft_nflag(t_player *players);
int						find_n(t_player **players, int old_n, int max_pl);
int						search_in_arr(int *arr, int num, int max_pl);
void					sort_players(t_player **players);
void					adjust_id(t_player *players, int *arr, int max_pl);
void					set_arr_m1(int max_pl, int *arr);
int						check_find_n(t_player **players, int *arr, int n, int max_pl);
void					add_to_arr(t_player *players, int *arr, int max_pl);

/*
**      game setup functions
*/
void					intro_players(t_player *players);
void					game_setup(t_player *players, t_game *game_data);
void					game_set_par(t_player *players);
int						count_players(t_player *players);
void					set_cursors(t_cursor *cursor, t_player *players);

/*
**      free functions
*/
void					free_cursor(t_cursor *cursor);
void					free_players(t_player *players);
void					free_arr(char **name);

/*
**		game loop functions
*/

void					game_loop(t_game *cw);
void					kill_cursor(t_game *cw, int id);

/*
**		generic operation functions
*/

void					get_operation(t_cursor *cursor, t_game *cw);
int						execute_operation(t_cursor *c, t_game *cw);
t_instruction			*new_instruction(void);
int						get_pos(int position, int distance);

/*
**		encoding byte functions
*/

int						encoding_byte(unsigned char data, t_instruction *ins, int *ret);
int						size_of_arg(t_instruction ins);

#endif
