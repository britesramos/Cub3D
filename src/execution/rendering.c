/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 14:38:09 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/28 15:05:29 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT))
		return ;
	mlx_put_pixel(data->img, x, y, color);
}

void	render_ceiling_floor(t_data *data, int ray, int top_pixel,
		int bottom_pixel)
{
	int	y;

	y = bottom_pixel;
	while (y < HEIGHT)
	{
		pixel_put(data, ray, y, data->mlx_textures->floor);
		y++;
	}
	y = 0;
	while (y < top_pixel)
	{
		pixel_put(data, ray, y, data->mlx_textures->ceiling);
		y++;
	}
}

void	rendering(t_data *data, int ray)
{
	double	top_pixel;
	double	bottom_pixel;
	double	wall_height;

	data->ray->wall_distance *= cos(angle_check(data->ray->ray_angle
				- data->player->angle));
	wall_height = (TILE_SIZE / data->ray->wall_distance)
		* ((WIDTH / 2) / tan(data->player->fov_rad / 2));
	top_pixel = (HEIGHT / 2) - (wall_height / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	data->ray->slice = ray;
	render_ceiling_floor(data, ray, top_pixel, bottom_pixel);
	render_walls(data, top_pixel, bottom_pixel, wall_height);
}
