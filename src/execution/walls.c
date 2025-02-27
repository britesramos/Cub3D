/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:32:33 by rkaras        #+#    #+#                 */
/*   Updated: 2025/02/26 15:51:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	get_texture(t_data *data, int int_type)
{
	data->ray->ray_angle = angle_check(data->ray->ray_angle);
	if (int_type == VERTICAL)
	{
		if (data->ray->ray_angle > PI / 2
			&& data->ray->ray_angle < 3 * (PI / 2))
			return (data->mlx_textures->ea);
		else
			return (data->mlx_textures->we);
	}
	else
}

void	draw_walls(t_data *data, int top_pixel, int bottom_pixel,
	double wall_height)
{
	double			x_offset;
	double			y_offset;
	mlx_texture_t	*texture;
	uint32_t		*array;
	double			scaling_factor;

	texture = get_texture(data, data->ray->intersection_type);
}