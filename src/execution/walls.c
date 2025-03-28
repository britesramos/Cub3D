/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:32:33 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/28 15:11:15 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*get_texture(t_data *data, int int_type)
{
	data->ray->ray_angle = angle_check(data->ray->ray_angle);
	if (int_type == HORIZONTAL)
	{
		if (data->ray->ray_angle > 0 && data->ray->ray_angle < PI)
			return (data->mlx_textures->so);
		else
			return (data->mlx_textures->no);
	}
	else
	{
		if (data->ray->ray_angle > PI / 2
			&& data->ray->ray_angle < 3 * (PI / 2))
			return (data->mlx_textures->we);
		else
			return (data->mlx_textures->ea);
	}
}

double	get_x_offset(mlx_texture_t *texture, t_data *data)
{
	double	x_offset;

	if (data->ray->intersection_type == VERTICAL)
	{
		x_offset = (int)fmodf((data->ray->vert_y
					* (texture->width / TILE_SIZE)), texture->width);
		if (data->ray->ray_angle > PI / 2 && data->ray->ray_angle < 3 * PI / 2)
			x_offset = texture->width - x_offset - 1;
	}
	else
	{
		x_offset = (int)fmodf((data->ray->horiz_x
					* (texture->width / TILE_SIZE)), texture->width);
		if (data->ray->ray_angle > 0 && data->ray->ray_angle < PI)
			x_offset = texture->width - x_offset - 1;
	}
	return (x_offset);
}

static int	swap_bytes(uint32_t c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	render_walls(t_data *data, int top_pixel, int bottom_pixel,
	double wall_height)
{
	mlx_texture_t	*texture;
	uint32_t		*array;
	double			scaling_factor;
	double			x_offset;
	double			y_offset;

	texture = get_texture(data, data->ray->intersection_type);
	array = (uint32_t *)texture->pixels;
	scaling_factor = (double)texture->height / wall_height;
	x_offset = get_x_offset(texture, data);
	if (x_offset < 0)
		x_offset = 0;
	y_offset = (top_pixel - (HEIGHT / 2) + (wall_height / 2)) * scaling_factor;
	if (y_offset < 0)
		y_offset = 0;
	while (top_pixel < bottom_pixel)
	{
		pixel_put(data, data->ray->slice, top_pixel, swap_bytes
			(array[((int)y_offset * texture->width) + (int)x_offset]));
		y_offset = y_offset + scaling_factor;
		top_pixel++;
	}
}
