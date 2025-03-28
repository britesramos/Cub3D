/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:51:42 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/28 12:37:29 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_rgb(t_data *data, char ch)
{
	int	red;
	int	green;
	int	blue;

	if (ch == 'c')
	{
		red = ft_atoi(data->c_color[0]);
		green = ft_atoi(data->c_color[1]);
		blue = ft_atoi(data->c_color[2]);
		data->mlx_textures->ceiling = (red << 24) | (green << 16)
			| (blue << 8) | 255;
		return (1);
	}
	else if (ch == 'f')
	{
		red = ft_atoi(data->f_color[0]);
		green = ft_atoi(data->f_color[1]);
		blue = ft_atoi(data->f_color[2]);
		data->mlx_textures->floor = (red << 24) | (green << 16)
			| (blue << 8) | 255;
		return (1);
	}
	else
		return (0);
}

void	init_textures(t_data *data)
{
	data->mlx_textures->so = mlx_load_png(data->so);
	if (!data->mlx_textures->so)
		error_print_exit(data, "Invalid south texture path\n", -3);
	data->mlx_textures->no = mlx_load_png(data->no);
	if (!data->mlx_textures->no)
		error_print_exit(data, "Invalid north texture path\n", -3);
	data->mlx_textures->ea = mlx_load_png(data->ea);
	if (!data->mlx_textures->ea)
		error_print_exit(data, "Invalid east texture path\n", -3);
	data->mlx_textures->we = mlx_load_png(data->we);
	if (!data->mlx_textures->we)
		error_print_exit(data, "Invalid west texture path\n", -3);
	if (init_rgb(data, 'f') == 0)
		error_print_exit(data, "Fail floor RGB init\n", -3);
	if (init_rgb(data, 'c') == 0)
		error_print_exit(data, "Fail ceiling RGB init\n", -3);
}
