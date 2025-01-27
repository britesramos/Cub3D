/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 14:30:52 by rkaras        #+#    #+#                 */
/*   Updated: 2025/01/27 15:43:42 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	angle_check(float angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

bool	wall_hit(double x, double y, t_data *data)
{
	double	x_map;
	double	y_map;

	if (x < 0 || y < 0)
		return (false);
	x_map = floor(x / TILE_SIZE);
	y_map = floor(y / TILE_SIZE);
	
}

int	inter_check(float angle, float *inter, float *step, int is_horizontal)
{
	if (is_horizontal)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (LEFT);
		}
	}
}


float	get_h_intersection(t_data *data, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, HORIZONTAL);
	
}

void	raycasting(t_data *data)
{
	double	h_intersection;
	double	v_intersection;
	int		ray;

	ray = 0;
	data->ray->ray_angle = data->player->angle - (data->player->fov_rad / 2);
	while (ray < WIDTH)
	{
		data->ray->intersection_type = VERTICAL;
		h_intersection = get_h_intersection(data, angle_check(data->ray->ray_angle));
		// v_intersection = //get_v_intersection
		if (v_intersection <= h_intersection)
			data->ray->wall_distance = v_intersection;
		else
		{
			data->ray->wall_distance = h_intersection;
			data->ray->intersection_type = HORIZONTAL;
		}
		//render_wall;
		ray++;
		data->ray->ray_angle += (data->player->fov_rad / WIDTH);
	}
}
