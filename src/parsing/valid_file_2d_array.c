/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_file_2d_array.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/24 00:36:31 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/24 00:36:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	all_textures_found(t_data *data)
{
	if (data->c_color == NULL || data->f_color == NULL || data->ea == NULL
		||data->no == NULL || data->so == NULL || data->we == NULL)
		error_print_exit(data, "Error\nNot all textures found.\n", -1);
	return (1);
}

static void	png_checker(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i])
		i++;
	i++;
	while (str[i] != '.' && str[i])
		i++;
	if (ft_strncmp(&str[i], ".png", 4) != 0)
		error_print_exit(data, "Error\nInvalid texture extension\n", -1);
}

static void	valid_texture_extension_checker(t_data *data)
{
	png_checker(data, data->ea);
	png_checker(data, data->no);
	png_checker(data, data->so);
	png_checker(data, data->we);
}

int	valid_file_2d_array(char **file_2d_array, t_data *data)
{
	if (parse_textures(file_2d_array, data) == 0)
		return (0);
	all_textures_found(data);
	valid_texture_extension_checker(data);
	valid_texture_rgb_checker(data);
	if (parse_map(file_2d_array, data) == 0)
		return (0);
	return (1);
}
