/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:51:42 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/27 10:19:19 by sramos        ########   odam.nl         */
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

void	init_textures(t_data *data)
{
	if (init_textures_util(data, data->so, data->mlx_textures->so) == 0)
		error_print_exit(data, "Fail tex to img : SO\n", -3);
	if (init_textures_util(data, data->no, data->mlx_textures->no) == 0)
		error_print_exit(data, "Fail tex to img : NO\n", -3);
	if (init_textures_util(data, data->ea, data->mlx_textures->ea) == 0)
		error_print_exit(data, "Fail tex to img : EA\n", -3);
	if (init_textures_util(data, data->we, data->mlx_textures->we) == 0)
		error_print_exit(data, "Fail tex to img : WE\n", -3);
}
