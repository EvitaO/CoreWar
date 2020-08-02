/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:42:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/02 19:07:41 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char *str_rev_by_2(char *str)
{
	int     i;
	int     j;
	char    *cp;

	cp = ft_strdup(str);
	i = 0;
	j = ft_strlen(str) - 1;
	while (j >= 0)
	{
		cp[i + 1] = str[j];
		cp[i] = str[j - 1];
		i = i + 2;
		j = j - 2;
	}
	return (cp);
}

void        get_data(int fd, t_player *players)
{
	int             i;
	unsigned int j;
	char            *str;
	char            *str2;

	//going to read magic header, convert to base 16, str rev by 2 chars
	i = read(fd, &j, 4);
	str = itoa_base(j, 16);
	str2 = itoa_base(COREWAR_EXEC_MAGIC, 16);;
	str[6] = '\0';
	str = str_rev_by_2(str);
	if (ft_strcmp(str, str2) != 0)
		exit(ft_printf("MAGIC HEADER IS NOT CORRECT\n"));
	//going to read players name and save it in players->name
	players->name = ft_strnew(PROG_NAME_LENGTH);
	i = read(fd, players->name, PROG_NAME_LENGTH);
	//reading the 4 NULL bytes
	i = read(fd, &j, 4);
	//reading the for bytes with size, but dont know how this works cause the number aint correct
	i = read(fd, &j, 4);
	ft_printf("%i\n", itoa_base(j, 10));
	//reading the comment and save it in players->comment
	players->comment = ft_strnew(COMMENT_LENGTH);
	i = read(fd, players->comment, COMMENT_LENGTH);
	//reading 4 NULL bytes
	i = read(fd, &j, 4);
	//while read is bigger then null i++, so then i get the correct size of code, was just trying things out
	i = 0;
	while (read(fd, &j, 1) > 0)
		i++;
	ft_printf("%i\n", i);
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
	while (players)
	{
		ft_printf("File is %s.cor\n\n", players->fname);
		ft_printf("* Player %i, \"%s\" (\"%s\") !\n", players->id, players->name, players->comment);
		players = players->next;
	}
}
