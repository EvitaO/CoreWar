/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 09:40:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 17:13:07 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft/includes/libft.h"
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

typedef struct			s_game
{
	int					player_l_alive;
	int					cycles_cnt;
	int					live_cnt;
	int					cycles_to_die;
	int					checks_cnt;
	int					players;
	unsigned char		arena[MEM_SIZE + 1];
}						t_game;

typedef struct			s_cursors
{
	int					id;
	int					carry;
	int					last_live;
	int					wait_cycles;
	int					pos;
	int					jump;
	//int                 reg[REG_NUMBER];
	struct s_cursors	*next;
	struct s_cursors	*prev;
}						t_cursors;

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
void					set_cursors(t_cursors *cursors, t_player *players);

/*
**      free functions
*/
void					free_cursor(t_cursors *cursors);
void					free_players(t_player *players);
void					free_arr(char **name);

#endif
