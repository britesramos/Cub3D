/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions_mm.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 10:49:16 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/27 17:12:19 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	to_close_to_wall(t_data *data, float x_inc, float y_inc)
{
	float	new_x;
	float	new_y;

	new_x = data->player->mm_pos_x + x_inc;
	new_y = data->player->mm_pos_y + y_inc;
	if (data->map[(int)(new_y - OFFSET)][(int)(new_x)] == '1' && y_inc < 0)
		return (1);
	if (data->map[(int)(new_y + OFFSET)][(int)(new_x)] == '1' && y_inc > 0)
		return (1);
	if (data->map[(int)(new_y)][(int)(new_x - OFFSET)] == '1' && x_inc < 0)
		return (1);
	if (data->map[(int)(new_y)][(int)(new_x + OFFSET)] == '1' && x_inc > 0)
		return (1);
	return (0);
}

static int	move(t_data *data, float x_increment, float y_increment)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = data->player->mm_pos_x + x_increment;
	new_y = data->player->mm_pos_y + y_increment;
	map_x = (int)new_x;
	map_y = (int)new_y;
	if (to_close_to_wall(data, x_increment, y_increment) == 1)
		return (0);
	if (data->map[map_y][map_x] == '0')
	{
		data->player->mm_pos_x = new_x;
		data->player->mm_pos_y = new_y;
		return (1);
	}
	return (0);
}

void	key_actions_mm(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	(void)keydata;
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move(data, -0.05, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move(data, 0.05, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move(data, 0, -0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move(data, 0, 0.05);
	mini_map(data);
}
