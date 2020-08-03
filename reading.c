/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:42:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/03 13:23:54 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		get_null_bytes(t_player *players, int fd)
{
	int				i;
	unsigned int	j;

	i = read(fd, &j, 4);
	if (i < 4 || j != 0)
		exit(ft_printf("Error NULL bytes\n"));
}

void		get_name_comment(t_player *players, int fd)
{
	int				i;
	unsigned int	j;

	players->name = ft_strnew(PROG_NAME_LENGTH);
	i = read(fd, players->name, PROG_NAME_LENGTH);
	if (i < PROG_NAME_LENGTH)
		exit(ft_printf("PROg name is wrong\n"));
	get_null_bytes(players, fd);
	i = read(fd, &j, 4);
	if (i < 4)
		exit(ft_printf("Error exec code size\n"));
	players->comment = ft_strnew(COMMENT_LENGTH);
	i = read(fd, players->comment, COMMENT_LENGTH);
	if (i < COMMENT_LENGTH)
		exit(ft_printf("Error comment length\n"));
}

void		get_code_size(t_player *players, int fd)
{
	int				i;
	unsigned int	j;

	players->code = ft_strnew(CHAMP_MAX_SIZE + 1);
	i = read(fd, players->code, CHAMP_MAX_SIZE + 5);
	if (i > CHAMP_MAX_SIZE)
		exit(ft_printf("exec code size is to big\n"));
	players->size = i;
}

void        get_data(int fd, t_player *players)
{
	int             i;
	unsigned int j;
	char            *str;
	char            *str2;

	i = read(fd, &j, 4);
	if (i < 4)
		exit(ft_printf("MAgic header error\n"));
	str = itoa_base(j, 16);
	str2 = itoa_base(COREWAR_EXEC_MAGIC, 16);;
	str[6] = '\0';
	str = str_rev_by_2(str);
	if (ft_strcmp(str, str2) != 0)
		exit(ft_printf("MAGIC HEADER IS NOT CORRECT\n"));
	free(str);
	free(str2);
	get_name_comment(players, fd);
	get_null_bytes(players, fd);
	get_code_size(players, fd);
}

void        read_args(char **argv, t_player *players)
{
	int     fd;

	while (players->next)
	{
		fd = open(argv[players->arg_n], O_RDONLY);
		get_data(fd, players);    
		players = players->next;
	}
	fd = open(argv[players->arg_n], O_RDONLY);
	get_data(fd, players);    
	while (players->prev)
		players = players->prev;
	intro_players(players);
}
