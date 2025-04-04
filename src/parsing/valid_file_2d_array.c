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
	if (data->parse_utils->c_util == NULL || data->parse_utils->f_util == NULL
		|| data->ea == NULL || data->no == NULL || data->so == NULL
		|| data->we == NULL)
		return (error_print_return("Not all textures found\n", 0));
	return (1);
}

static int	png_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (is_space(str[i]))
		i--;
	if (ft_strlen(str) < 4)
		return (error_print_return("Invalid texture\n", 0));
	if (ft_strncmp(&str[i - 3], ".png", 4) != 0)
		return (error_print_return("Invalid texture extension\n", 0));
	return (1);
}

static int	valid_texture_extension_checker(t_data *data)
{
	if (!png_checker(data->ea))
		return (0);
	if (!png_checker(data->no))
		return (0);
	if (!png_checker(data->so))
		return (0);
	if (!png_checker(data->we))
		return (0);
	return (1);
}

int	valid_file_2d_array(char **file_2d_array, t_data *data)
{
	if (!parse_textures(file_2d_array, data))
		return (0);
	if (!all_textures_found(data))
		return (0);
	if (!valid_texture_rgb_checker(data))
		return (0);
	if (!valid_texture_extension_checker(data))
		return (0);
	if (!parse_map(file_2d_array, data))
		return (0);
	return (1);
}
