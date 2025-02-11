/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 14:38:09 by rkaras        #+#    #+#                 */
/*   Updated: 2025/02/11 16:00:34 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_wall(t_data *data, int ray)
{
	double	wall_height;
	double	bottom_pixel;
	double	top_pixel;

	data->ray->wall_distance *= cos(angle_check(data->ray->ray_angle
				- data->player->angle));
	wall_height = (TILE_SIZE / data->ray->wall_distance)
		* ((WIDTH / 2) / tan(data->player->fov_rad / 2));
	bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
	top_pixel = (HEIGHT / 2) - (wall_height / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	
}
