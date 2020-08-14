/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_rev_by_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 13:20:25 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/14 16:10:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char		*str_rev_by_2(char *str)
{
	int		i;
	int		j;
	char	*cp;

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
	free(str);
	return (cp);
}
