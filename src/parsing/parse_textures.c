/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/27 13:52:33 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/27 13:52:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_i(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) || str[i] == '	')
		i++;
	if (ft_strncmp(&str[i], "SO", 2))
		return (1);
	else if (ft_strncmp(&str[i], "NO", 2))
		return (1);
	else if (ft_strncmp(&str[i], "EA", 2))
		return (1);
	else if (ft_strncmp(&str[i], "WE", 2))
		return (1);
	else if (ft_strncmp(&str[i], "F", 1))
		return (2);
	else if (ft_strncmp(&str[i], "C", 1))
		return (2);
	return (0);
}

static int	get_len(char *str, int i)
{
	int	len;

	len = 0;
	while (is_space(str[i]) || str[i] == '	')
		i++;
	while (str[i + len])
		len++;
	return (len);
}

static char	*add_texture_utils(t_data *data, char *texture, char *str, char **file_2d_array)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (get_i(str) == 1)
		i = 2;
	else if (get_i(str) == 2)
		i = 1;
	len = get_len(str, 2);
	while (is_space(str[i]))
		i++;
	texture = ft_calloc(sizeof(char), len + 1);
	if (!texture)
	{
		free_char_pointer_pointer(file_2d_array);
		error_print_exit(data, "Error\nFail to alloc for new texture.\n", -1);
	}
	ft_strlcpy(texture, &str[i], len + 4);
	return (texture);
}

static void	add_texture_data(t_data *data, char *str, int type, char **file_2d_array)
{
	int	len;

	len = 0;
	if ((type == C && data->parse_utils->c == true) || (type == F && data->parse_utils->f == true)
		|| (type == SO && data->parse_utils->so == true) || (type == NO && data->parse_utils->no == true)
		|| (type == EA && data->parse_utils->ea == true) || (type == WE && data->parse_utils->we == true))
	{
		free_char_pointer_pointer(file_2d_array);
		error_print_exit(data, "To many textures\n", -1);
	}
	if (type == SO || type == NO || type == EA || type == WE)
	{
		if (type == SO && data->parse_utils->so == false)
		{
			data->so = add_texture_utils(data, data->so, str, file_2d_array);
			data->parse_utils->so = true;
		}
		else if (type == NO && data->parse_utils->no == false)
		{
			data->no = add_texture_utils(data, data->no, str, file_2d_array);
			data->parse_utils->no = true;
		}
		else if (type == EA && data->parse_utils->ea == false)
		{
			data->ea = add_texture_utils(data, data->ea, str, file_2d_array);
			data->parse_utils->ea = true;
		}
		else if (type == WE && data->parse_utils->we == false)
		{
			data->we = add_texture_utils(data, data->we, str, file_2d_array);
			data->parse_utils->we = true;
		}
	}
	else if (type == C || type == F)
	{
		if (type == C && data->parse_utils->c == false)
		{
			data->c_color = add_texture_utils(data, data->c_color, str, file_2d_array);
			data->parse_utils->c = true;
		}
		else if (type == F && data->parse_utils->f == false)
		{
			data->f_color = add_texture_utils(data, data->f_color, str, file_2d_array);
			data->parse_utils->f = true;
		}
	}
}

int	parse_textures(char **file_2d_array, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file_2d_array[i])
	{
		while (is_space(file_2d_array[i][j]))
			j++;
		if (!ft_strncmp(&file_2d_array[i][j], "SO", 2))
			add_texture_data(data, file_2d_array[i], SO, file_2d_array);
		else if (!ft_strncmp(&file_2d_array[i][j], "NO", 2))
			add_texture_data(data, &file_2d_array[i][j], NO, file_2d_array);
		else if (!ft_strncmp(&file_2d_array[i][j], "EA", 2))
			add_texture_data(data, file_2d_array[i], EA, file_2d_array);
		else if (!ft_strncmp(&file_2d_array[i][j], "WE", 2))
			add_texture_data(data, file_2d_array[i], WE, file_2d_array);
		else if (!ft_strncmp(&file_2d_array[i][j], "C", 1))
			add_texture_data(data, file_2d_array[i], C, file_2d_array);
		else if (!ft_strncmp(&file_2d_array[i][j], "F", 1))
			add_texture_data(data, file_2d_array[i], F, file_2d_array);
		j = 0;
		i++;
	}
	return (1);
}
