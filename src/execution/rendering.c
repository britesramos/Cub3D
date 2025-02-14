/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 14:38:09 by rkaras        #+#    #+#                 */
/*   Updated: 2025/02/14 16:04:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_data *data, int ray, int top_pixel)
{
	int	ceiling;

	ceiling = 0;
	while (ceiling < top_pixel)
	{
		if (ray < 0)
			return ;
		else if (ray >= WIDTH)
			return ;
		mlx_put_pixel(data->img, ray, ceiling, data->mlx_textures->ceiling);
		ceiling++;
	}
}

void	render_wall(t_data *data, int ray)
{
	double	wall_height;
	double	bottom_pixel;
	double	top_pixel;

	data->ray->wall_distance *= cos(angle_check(data->ray->ray_angle
				- data->player->angle));
	wall_height = (TILE_SIZE / data->ray->wall_distance)
		* ((WIDTH / 2) / tan(data->player->fov_rad / 2));
	//probati shvatiti zasto ne radi bez ovog clampinga
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	wall_height /= WIDTH / 800;
	bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
	top_pixel = (HEIGHT / 2) - (wall_height / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;

	draw_ceiling(data, ray, top_pixel);
}
