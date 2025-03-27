/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:43:26 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/27 13:31:53 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	release_key(mlx_key_data_t keydata, t_data *data)
{
	data->player->horizontal = 0;
	data->player->horizontal = 0;
	data->player->vertical = 0;
	data->player->vertical = 0;
	data->player->rotation = 0;
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
