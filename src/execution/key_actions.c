/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:43:26 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/20 16:15:30 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//TO DO - WRITE key_actions function.
//If press ESC
	//mlx_close_window(data->mlx);
//USE ARROWS.
//Rotate right. (Arrow)
//Rotate left. (Arrow)
//Move right. (D)
//Move left. (A)
//Move forward. (W)
//Move back. (S)

// EXAMPLE so_long:

// void	move_right(t_data *data)
// {
// 	if (data->map[data->player_position_y][data->player_position_x + 1] != '1')
// 	{
// 		data->textures.player->instances->x += PIXELS;
// 		data->player_position_x++;
// 		data->moves++;
// 		printf("%i\n", data->moves);
// 		c_cleaner(data, data->player_position_x, data->player_position_y);
// 	}
// 	home_end_data(data, data->player_position_x, data->player_position_y);
// }

// void	key_actions(mlx_key_data_t keydata, void *param)
// {
// 	t_data *data;

// 	data = (t_data *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		ft_putendl_fd("	Goodbye 👋", 1);
// 		mlx_close_window(data->mlx);
// 	}
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 		move_infront(data);
// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
// 		move_back(data);
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
// 		move_left(data);
// 	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
// 		move_right(data);
// 	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
// 		rotate_left(data);
// 	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
// 		rotate_right(data);
// }
