/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 17:31:35 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/08/09 18:00:15 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void            free_cursor(t_cursors *cursors)
{
    t_cursors   *tmp;

    while (cursors)
    {
        tmp = cursors->prev;
        free(cursors);
        cursors = tmp;
    }
    free(cursors);
}

//  int             id;
//     char            *fname;
//     header_t        *data;
//     unsigned char   *code;
//     int             n_flag;
//     int             arg_n;
//     int             cursor;
//     struct s_player *prev;
//     struct s_player *next;

void            free_players(t_player *players)
{
    t_player    *tmp;

    while (players)
    {
        tmp = players->next;
        free(players->data);
        free(players->fname);
        free(players->code);
        free(players);
        players = tmp;
    }
    free(players);
}
