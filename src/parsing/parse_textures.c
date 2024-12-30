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

static char	*add_texture_utils(t_data *data, char *texture, char *str, int len)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	texture = ft_calloc(sizeof(char), len + 1);
	if (!texture)
		error_print_exit(data, "Error\nFail to alloc for new texture.\n", -1);
	ft_strlcpy(texture, &str[i], len + 4);
	return (texture);
}

static int	get_len(char *str, int i)
{
	int	len;

	len = 0;
	while (is_space(str[i]))
		i++;
	while (str[i + len])
		len++;
	return (len);
}

static void	add_texture_data(t_data *data, char *str, int type)
{
	int	len;

	len = 0;
	if (type == SO || type == NO || type == EA || type == WE)
	{
		len = get_len(str, 2);
		if (type == SO)
			data->so = add_texture_utils(data, data->so, str, len);
		else if (type == NO)
			data->no = add_texture_utils(data, data->no, str, len);
		else if (type == EA)
			data->ea = add_texture_utils(data, data->ea, str, len);
		else if (type == WE)
			data->we = add_texture_utils(data, data->we, str, len);
	}
	else if (type == C || type == F)
	{
		len = get_len(str, 1);
		if (type == C)
			data->c_color = add_texture_utils(data, data->c_color, str, len);
		else if (type == F)
			data->f_color = add_texture_utils(data, data->f_color, str, len);
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
			add_texture_data(data, file_2d_array[i], SO);
		else if (!ft_strncmp(&file_2d_array[i][j], "NO", 2))
			add_texture_data(data, &file_2d_array[i][j], NO);
		else if (!ft_strncmp(&file_2d_array[i][j], "EA", 2))
			add_texture_data(data, file_2d_array[i], EA);
		else if (!ft_strncmp(&file_2d_array[i][j], "WE", 2))
			add_texture_data(data, file_2d_array[i], WE);
		else if (!ft_strncmp(&file_2d_array[i][j], "C", 1))
			add_texture_data(data, file_2d_array[i], C);
		else if (!ft_strncmp(&file_2d_array[i][j], "F", 1))
			add_texture_data(data, file_2d_array[i], F);
		j = 0;
		i++;
	}
	return (1);
}
