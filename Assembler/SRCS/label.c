/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:46:37 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:29 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void		store_label(char *label, t_data *data)
{
	if (!data->label)
	{
		data->label = (t_label*)ft_memalloc(sizeof(t_label));
		data->label->name = ft_strdup(label);
		data->label->op_nbr = data->op_nbr;
	}
	else
	{
		data->label->next = (t_label*)ft_memalloc(sizeof(t_label));
		data->label->next->prev = data->label;
		data->label = data->label->next;
		data->label->name = ft_strdup(label);
		data->label->op_nbr = data->op_nbr;
	}
}

void		check_label(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(LABEL_CHARS, s[i]))
			i++;
		else
			error("label_chars are incorrect", 0);
	}
}

static void	cut_only_label(char **line, char **label)
{
	int		i;
	char	*tmp;

	i = 2;
	*line = ft_strdup(label[1]);
	while (label[i])
	{
		tmp = ft_strjoin(*line, ":");
		free(*line);
		*line = tmp;
		tmp = ft_strjoin(*line, label[i]);
		free(*line);
		*line = ft_strtrim(tmp);
		i++;
	}
}

char		*check_if_label(char **line, t_data *data)
{
	char	**label;
	char	*tmp;

	tmp = NULL;
	label = ft_strsplit(*line, ':');
	if (label[0])
	{
		if (ft_strchr(label[0], '%'))
		{
			free_array_str(&label, NULL, 0);
			return (tmp);
		}
		check_label(label[0]);
		store_label(label[0], data);
		if (label[1])
			cut_only_label(&tmp, label);
	}
	free_array_str(&label, NULL, 0);
	return (tmp);
}
