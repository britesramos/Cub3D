/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 23:36:42 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/28 23:36:42 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	delete_images(t_data *data)
// {
// 	mlx_delete_image(data->mlx, data->mlx_textures->ea);
// 	mlx_delete_image(data->mlx, data->mlx_textures->no);
// 	mlx_delete_image(data->mlx, data->mlx_textures->so);
// 	mlx_delete_image(data->mlx, data->mlx_textures->we);
// }

void	free_char_pointer(char *str)
{
	free(str);
	str = NULL;
}

void	free_char_pointer_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	clean_up(t_data *data)
{
	if (data->c_color)
		free_char_pointer_pointer(data->c_color);
	if (data->f_color)
		free_char_pointer_pointer(data->f_color);
	if (data->ea)
		free_char_pointer(data->ea);
	if (data->no)
		free_char_pointer(data->no);
	if (data->so)
		free_char_pointer(data->so);
	if (data->we)
		free_char_pointer(data->we);
	if (data->map)
		free_char_pointer_pointer(data->map);
	if (data->player_facing)
		free_char_pointer(data->player_facing);
	if (data->parse_utils)
		free(data->parse_utils);
	if (data->mlx_textures)
		free(data->mlx_textures);
	if (data->player)
		free(data->player);
	if (data)
		free(data);
}
