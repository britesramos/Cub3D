/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:32:33 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/11 17:24:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*get_texture(t_data *data, int int_type)
{
	data->ray->ray_angle = angle_check(data->ray->ray_angle);
	if (int_type == VERTICAL)
	{
		if (data->ray->ray_angle > PI / 2
			&& data->ray->ray_angle < 3 * (PI / 2))
		{
			// printf("Selected texture: EAST (%p)\n", data->mlx_textures->ea);
			return (data->mlx_textures->ea);
		}
		else
		{
			// printf("Selected texture: WEST (%p)\n", data->mlx_textures->we);
			return (data->mlx_textures->we);
		}
	}
	else
	{
		if (data->ray->ray_angle > 0 && data->ray->ray_angle < PI)
		{
			// printf("Selected texture: SOUTH (%p)\n", data->mlx_textures->so);
			return (data->mlx_textures->so);
		}
		else
		{
			// printf("Selected texture: NORTH (%p)\n", data->mlx_textures->no);
			return (data->mlx_textures->no);
		}
	}
}

double	get_x_offset(mlx_texture_t *texture, t_data *data)
{
	double	x_offset;

	if (data->ray->intersection_type == HORIZONTAL)
		x_offset = (int)fmodf((data->ray->horiz_x
					* (texture->width / TILE_SIZE)), texture->width);
	else
		x_offset = (int)fmodf((data->ray->vert_y
					* (texture->width / TILE_SIZE)), texture->width);
	return (x_offset);
}

void	pixel_to_the_wall(t_data *data, int slice, double top_pixel, int color)
{
	if (slice < 0 || slice >= WIDTH || top_pixel < 0
		|| top_pixel >= HEIGHT)
		return ;
	mlx_put_pixel(data->img, slice, top_pixel, color);
}

int	shift_color_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
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
	array = (uint32_t *)texture->pixels;
	scaling_factor = (double)texture->height / wall_height;
	x_offset = get_x_offset(texture, data);
	y_offset = (top_pixel - (HEIGHT / 2) + (wall_height / 2)) * scaling_factor;
	if (y_offset < 0)
		y_offset = 0;
	if (x_offset < 0)
		x_offset = 0;
	while (top_pixel < bottom_pixel)
	{
		// if (x_offset >= texture->width)
		// 	x_offset = texture->width - 1;
		// if (y_offset >= texture->height)
		// 	y_offset = texture->height - 1;
		pixel_to_the_wall(data, data->ray->slice, top_pixel, shift_color_bytes
			(array[((int)y_offset * texture->width) + (int)x_offset]));
		y_offset += scaling_factor;
		top_pixel++;
	}
}
