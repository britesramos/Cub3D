/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:43:26 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/27 16:26:03 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	release_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_A)
		data->player->horizontal = 0;
	else if (keydata.key == MLX_KEY_D)
		data->player->horizontal = 0;
	else if (keydata.key == MLX_KEY_S)
		data->player->vertical = 0;
	else if (keydata.key == MLX_KEY_W)
		data->player->vertical = 0;
	else if (keydata.key == MLX_KEY_LEFT)
		data->player->rotation = 0;
	else if (keydata.key == MLX_KEY_RIGHT)
		data->player->rotation = 0;
}

void	key_actions(mlx_key_data_t keydata, void *data)
{
	t_data	*input;

	input = data;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			error_print_exit(input, "Good bye!", 1);
			mlx_close_window(input->mlx);
		}
		else if (keydata.key == MLX_KEY_A)
			input->player->horizontal = LEFT;
		else if (keydata.key == MLX_KEY_D)
			input->player->horizontal = RIGHT;
		else if (keydata.key == MLX_KEY_S)
			input->player->vertical = DOWN;
		else if (keydata.key == MLX_KEY_W)
			input->player->vertical = UP;
		else if (keydata.key == MLX_KEY_LEFT)
			input->player->rotation = LEFT;
		else if (keydata.key == MLX_KEY_RIGHT)
			input->player->rotation = RIGHT;
	}
	else if (keydata.action == MLX_RELEASE)
		release_key(keydata, input);
}
