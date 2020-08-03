/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 09:40:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/03 13:21:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct      s_player
{
    int             id;
    char            *fname;
    char            *name;
    char            *comment;
    unsigned char   *code;
    int             size;
    int             n_flag;
    int             arg_n;
    struct s_player *prev;
    struct s_player *next;
}                   t_player;

void                ft_nflag(t_player *players);
void                read_args(char **argv, t_player *players);
void                check_arg(int argc, char **argv, t_player *players);
char                *itoa_base(unsigned long long nbr, int base);
int					ft_atoi2(const char *str);
void                intro_players(t_player *players);
char                *str_rev_by_2(char *str);


#endif