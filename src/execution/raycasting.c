/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 14:30:52 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/28 15:03:33 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wall_hit(double x, double y, t_data *data)
{
	double	x_map;
	double	y_map;

	if (x < 0 || y < 0)
		return (0);
	x_map = floor(x / TILE_SIZE);
	y_map = floor(y / TILE_SIZE);
	if (y_map >= data->map_height || x_map >= data->map_width)
		return (0);
	if (data->map[(int)y_map] && x_map <= (int)ft_strlen(data->map[(int)y_map]))
	{
		if (data->map[(int)y_map][(int)x_map] == '1')
			return (0);
	}
	return (1);
}

double	h_inter(t_data *data, double angle)
{
	double	h_x;
	double	h_y;
	double	x_step;
	double	y_step;
	int		pixel;

	h_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	y_step = TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, HORIZONTAL);
	h_x = data->player->pos_x + (h_y - data->player->pos_y) / tan(angle);
	if ((!circle_check(angle, 'y') && x_step < 0)
		|| (circle_check(angle, 'y') && x_step > 0))
		x_step = x_step * -1;
	while (wall_hit(h_x, h_y - pixel, data))
	{
		h_x = h_x + x_step;
		h_y = h_y + y_step;
	}
	data->ray->horiz_x = h_x;
	data->ray->horiz_y = h_y;
	return (sqrt(pow(h_x - data->player->pos_x, 2)
			+ pow(h_y - data->player->pos_y, 2)));
}

double	v_inter(t_data *data, double angle)
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;
	int		pixel;

	v_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE;
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	pixel = inter_check(angle, &v_x, &x_step, VERTICAL);
	v_y = data->player->pos_y + (v_x - data->player->pos_x) * tan(angle);
	if ((!circle_check(angle, 'x') && y_step > 0)
		|| (circle_check(angle, 'x') && y_step < 0))
		y_step = y_step * -1;
	while (wall_hit(v_x - pixel, v_y, data))
	{
		v_x = v_x + x_step;
		v_y = v_y + y_step;
	}
	data->ray->vert_x = v_x;
	data->ray->vert_y = v_y;
	return (sqrt(pow(v_x - data->player->pos_x, 2)
			+ pow(v_y - data->player->pos_y, 2)));
}

void	raycasting(t_data *data)
{
	int		ray;
	double	h_intersection;
	double	v_intersection;

	data->ray->ray_angle = data->player->angle - (data->player->fov_rad / 2);
	ray = 0;
	while (ray < WIDTH)
	{
		h_intersection = h_inter(data, data->ray->ray_angle);
		v_intersection = v_inter(data, data->ray->ray_angle);
		data->ray->intersection_type = VERTICAL;
		if (v_intersection <= h_intersection)
			data->ray->wall_distance = v_intersection;
		else
		{
			data->ray->intersection_type = HORIZONTAL;
			data->ray->wall_distance = h_intersection;
		}
		rendering(data, ray);
		ray++;
		data->ray->ray_angle = data->ray->ray_angle
			+ (data->player->fov_rad / WIDTH);
	}
}
