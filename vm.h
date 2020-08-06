/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 09:40:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/06 17:50:38 by anonymous     ########   odam.nl         */
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
    header_t        *data;
    unsigned char   *code;
    int             n_flag;
    int             arg_n;
    int             cursor;
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