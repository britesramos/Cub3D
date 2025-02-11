/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:51:42 by sramos        #+#    #+#                 */
/*   Updated: 2025/02/11 17:13:12 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_textures_util(t_data *data, char *png, mlx_image_t *mlx_t)
{
	mlx_texture_t	*tex;

	tex = NULL;
	tex = mlx_load_png(png);
	if (!tex)
		error_print_exit(data, "Fail to load png.\n", -3);
	mlx_t = mlx_texture_to_image(data->mlx, tex);
	if (!mlx_t)
		return (0);
	mlx_delete_texture(tex);
	return (1);
}

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
		data->mlx_textures->ceiling = (red << 16) | (green << 8) | blue;
		return (1);
	}
	else if (ch == 'f')
	{
		red = ft_atoi(data->f_color[0]);
		green = ft_atoi(data->f_color[1]);
		blue = ft_atoi(data->f_color[2]);
		data->mlx_textures->floor = (red << 16) | (green << 8) | blue;
		return (1);
	}
	else
		return (0);
}

void	init_textures(t_data *data)
{
	if (init_rgb(data, 'f') == 0)
		error_print_exit(data, "Fail floor RGB init\n", -3);
	if (init_rgb(data, 'c') == 0)
		error_print_exit(data, "Fail ceiling RGB init\n", -3);
	if (init_textures_util(data, data->so, data->mlx_textures->so) == 0)
		error_print_exit(data, "Fail tex to img : SO\n", -3);
	if (init_textures_util(data, data->no, data->mlx_textures->no) == 0)
		error_print_exit(data, "Fail tex to img : NO\n", -3);
	if (init_textures_util(data, data->ea, data->mlx_textures->ea) == 0)
		error_print_exit(data, "Fail tex to img : EA\n", -3);
	if (init_textures_util(data, data->we, data->mlx_textures->we) == 0)
		error_print_exit(data, "Fail tex to img : WE\n", -3);
}
