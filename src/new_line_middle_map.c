/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_line_middle_map.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/24 17:34:32 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/24 17:34:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\b')
		return (1);
	return (0);
}

static int	only_white_spaces_left(char *str, int i)
{
	while (str[i])
	{
		if (!is_space(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	new_line_middle_map(char *str)
{
	int		i;
	bool	inside_map;

	i = 0;
	inside_map = false;
	while (str[i])
	{
		if (str[i] == '\n' && inside_map == false)
		{
			while (is_space(str[i]))
				i++;
			i++;
			if (str[i] == '1')
				inside_map = true;
		}
		if (inside_map == true && str[i] == '\n' && str[i + 1] == '\n')
		{
			if (!only_white_spaces_left(str, i))
				return (0);
		}
		i++;
	}
	return (1);
}
