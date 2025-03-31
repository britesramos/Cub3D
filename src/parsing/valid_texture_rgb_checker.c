/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_texture_rgb_checker.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/31 14:10:07 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/31 14:10:07 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	more_than_spaces_left(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	cpy_value_to_data(char **str, char **dst)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (str[i])
	{
		while (is_space(str[i][j]))
			j++;
		while (str[i][j + c] && !is_space(str[i][j + c]))
			c++;
		if (!more_than_spaces_left(&str[i][j + c]))
			return (0);
		dst[i] = ft_calloc(sizeof(char), c + 1);
		if (!dst[i])
			return (0);
		ft_strlcpy(dst[i], &str[i][j], c + 1);
		c = 0;
		j = 0;
		i++;
	}
	return (1);
}

static int	parse_rgb(char *str, char **dst)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ',');
	if (!split)
		return (0);
	while (split[i])
		i++;
	if (i != 3)
	{
		free_char_pointer_pointer(split);
		return (0);
	}
	if (!cpy_value_to_data(split, dst))
	{
		free_char_pointer_pointer(split);
		return (0);
	}
	free_char_pointer_pointer(split);
	return (1);
}

static int	commas_misconfiguration(char *str)
{
	int	i;
	int	c_commas;

	i = 0;
	c_commas = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == ',')
		return (1);
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
		else if (str[i] == ',')
			c_commas++;
		i++;
	}
	if (c_commas != 2)
		return (1);
	return (0);
}

int	valid_texture_rgb_checker(t_data *data)
{
	if (commas_misconfiguration(data->parse_utils->c_util))
		return (0);
	if (commas_misconfiguration(data->parse_utils->f_util))
		return (0);
	if (!parse_rgb(data->parse_utils->c_util, data->c_color))
		return (0);
	if (!parse_rgb(data->parse_utils->f_util, data->f_color))
		return (0);
	if (!check_rgb(data->c_color))
		return (0);
	if (!check_rgb(data->f_color))
		return (0);
	return (1);
}
