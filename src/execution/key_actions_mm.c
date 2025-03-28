/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions_mm.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 10:49:16 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/27 16:24:36 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
