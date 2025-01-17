/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:43:26 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/17 12:32:04 by sramos        ########   odam.nl         */
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

// void	move_right(t_game *game)
// {
// 	if (game->map[game->player_position_y][game->player_position_x + 1] != '1')
// 	{
// 		game->textures.player->instances->x += PIXELS;
// 		game->player_position_x++;
// 		game->moves++;
// 		printf("%i\n", game->moves);
// 		c_cleaner(game, game->player_position_x, game->player_position_y);
// 	}
// 	home_end_game(game, game->player_position_x, game->player_position_y);
// }

// void	ft_key_actions(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		ft_putendl_fd("	Goodbye 👋", 1);
// 		mlx_close_window(game->mlx);
// 	}
// 	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
// 		move_up(game);
// 	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
// 		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
// 		move_down(game);
// 	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
// 		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
// 		move_left(game);
// 	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
// 		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
// 		move_right(game);
// }