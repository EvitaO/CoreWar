/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 09:40:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/30 16:53:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"
# include "vm_structs.h"
# include <fcntl.h>

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
int						execute_operation(t_cursor *c, t_game *cw, t_ops op);
int						get_pos(int position, int distance);
t_instruction			*new_instruction(void);

/*
**		encoding byte functions
*/
int						encoding_byte(unsigned char data, t_instruction *ins, int *ret);
int						size_of_arg(t_instruction ins, int arg);
int						check_registries(t_instruction ins);

/*
**		operations
*/

int						live(t_cursor *c, t_game *cw);
int						ld(t_cursor *c, t_game *cw);


#endif