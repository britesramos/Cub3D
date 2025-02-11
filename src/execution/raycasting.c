/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 14:30:52 by rkaras        #+#    #+#                 */
/*   Updated: 2025/02/11 16:19:48 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	wall_hit(double x, double y, t_data *data)
{
	double	x_map;
	double	y_map;

	if (x < 0 || y < 0)
		return (false);
	x_map = floor(x / TILE_SIZE);
	y_map = floor(y / TILE_SIZE);
	if (y_map >= data->map_height || x_map >= data->map_width)
		return (false);
	if (data->map[(int)y_map] && x_map <= ft_strlen(data->map[(int)y_map]))
	{
		if (data->map[(int)y_map][(int)x_map] == '1')
			return (true);
	}
	return (false);
}

double	get_h_inter(t_data *data, double angle)
{
	double	h_x;
	double	h_y;
	double	x_step;
	double	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, HORIZONTAL);
	h_x = data->player->pos_x + (h_y - data->player->pos_y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0)
		|| (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - data->player->pos_x, 2)
			+ pow(h_y - data->player->pos_y, 2)));
}

double	get_v_inter(t_data *data, double angle)
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE / tan(angle);
	v_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &v_x, &x_step, VERTICAL);
	v_y = data->player->pos_y + (v_x - data->player->pos_x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0)
		|| (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - data->player->pos_x, 2)
			+ pow(v_y - data->player->pos_y, 2)));
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
		h_intersection = get_h_inter(data, angle_check(data->ray->ray_angle));
		v_intersection = get_v_inter(data, angle_check(data->ray->ray_angle));
		if (v_intersection <= h_intersection)
			data->ray->wall_distance = v_intersection;
		else
		{
			data->ray->wall_distance = h_intersection;
			data->ray->intersection_type = HORIZONTAL;
		}
		// render_wall(data, ray);
		ray++;
		data->ray->ray_angle += (data->player->fov_rad / WIDTH);
	}
}
