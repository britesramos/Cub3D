/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 18:47:44 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/28 11:31:13 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	facing_angle(char *player_facing)
{
	double	angle;

	if (strcmp(player_facing, "N") == 0)
		angle = (3 * PI) / 2;
	else if (strcmp(player_facing, "S") == 0)
		angle = PI / 2;
	else if (strcmp(player_facing, "E") == 0)
		angle = 0;
	else
		angle = PI;
	return (angle);
}

void	rotate_player(t_data *data, int i)
{
	if (i == RIGHT)
	{
		data->player->angle += PLAYER_ROTATION_SPEED;
		data->player->angle = angle_check(data->player->angle);
	}
	else if (i == LEFT)
	{
		data->player->angle -= PLAYER_ROTATION_SPEED;
		data->player->angle = angle_check(data->player->angle);
	}
}

void	move_player(t_data *data, double move_x, double move_y)
{
	float	new_x;
	float	new_y;
	int	map_x;
	int	map_y;

	new_x = roundf(data->player->pos_x + move_x);
	new_y = roundf(data->player->pos_y + move_y);
	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (map_x < 0 || map_y < 0 || map_x >= data->map_width
		|| map_y >= data->map_height)
		return ;
	if (data->map[map_y][map_x] != '1' &&
		data->map[map_y][data->player->pos_x / TILE_SIZE] != '1' &&
		data->map[data->player->pos_y / TILE_SIZE][map_x] != '1')
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
		data->player->mm_pos_x = (new_x + (MM_TILE_SIZE / 2.3)) / TILE_SIZE;
		data->player->mm_pos_y = (new_y + (MM_TILE_SIZE / 2.3)) / TILE_SIZE;
	}
}

void	hook_player_directions(t_data *data, double move_x, double move_y)
{
	if (data->player->horizontal == RIGHT)
	{
		move_x = -sin(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = cos(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	if (data->player->horizontal == LEFT)
	{
		move_x = sin(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = -cos(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	if (data->player->vertical == UP)
	{
		move_x = cos(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = sin(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	if (data->player->vertical == DOWN)
	{
		move_x = -cos(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = -sin(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	if (data->player->rotation == RIGHT)
		rotate_player(data, RIGHT);
	if (data->player->rotation == LEFT)
		rotate_player(data, LEFT);
	move_player(data, move_x, move_y);
}
