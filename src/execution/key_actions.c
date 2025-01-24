/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:43:26 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/24 18:46:31 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	release_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		data->player->horizontal = 0;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		data->player->horizontal = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		data->player->vertical = 0;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		data->player->vertical = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		data->player->rotation = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		data->player->rotation = 0;
}

void	key_actions(mlx_key_data_t keydata, void *data)
{
	t_data	*input;
	
	input = data;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) //Segfault here somewhere.
	{
		error_print_exit(input, "Good bye!", 1);
		mlx_close_window(input->mlx);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		input->player->horizontal = LEFT;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		input->player->horizontal = RIGHT;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		input->player->vertical = DOWN;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		input->player->vertical = UP;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		input->player->rotation = LEFT;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		input->player->rotation = RIGHT;
	release_key(keydata, input);
}
