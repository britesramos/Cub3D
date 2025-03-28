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

static void	delete_mlx_textures(t_mlx_textures *textures)
{
	if (textures->ea)
		mlx_delete_texture(textures->ea);
	if (textures->no)
		mlx_delete_texture(textures->no);
	if (textures->so)
		mlx_delete_texture(textures->so);
	if (textures->we)
		mlx_delete_texture(textures->we);
	if (textures)
		free(textures);
}

static void	clean_up_textures(t_data *data)
{
	if (data->c_color)
		free_char_pointer_pointer(data->c_color);
	if (data->f_color)
		free_char_pointer_pointer(data->f_color);
	if (data->ea)
		free(data->ea);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
}

void	clean_up(t_data *data)
{
	clean_up_textures(data);
	if (data->parse_utils->f_util)
		free(data->parse_utils->f_util);
	if (data->parse_utils->c_util)
		free(data->parse_utils->c_util);
	if (data->map)
		free_char_pointer_pointer(data->map);
	if (data->player_facing)
		free_char_pointer(data->player_facing);
	if (data->parse_utils)
		free(data->parse_utils);
	if (data->mlx_textures)
		delete_mlx_textures(data->mlx_textures);
	if (data->player)
		free(data->player);
	if (data->mini_map)
		free(data->mini_map);
	if (data->ray)
		free(data->ray);
	if (data)
		free(data);
}
