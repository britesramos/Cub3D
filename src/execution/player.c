/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 18:47:44 by rkaras        #+#    #+#                 */
/*   Updated: 2025/01/24 16:58:27 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// convention (2d Cartesian angle system) is that the east position is 0 because it aligns with the x axis, and then we increase
// by 90 in counter-clockwise direction

double	facing_angle(char *player_facing)
{
	double	angle;

	if (strcmp(player_facing, "N") == 0)
		angle = PI / 2; // 90
	else if (strcmp(player_facing, "S") == 0)
		angle = (3 * PI) / 2; // 270
	else if (strcmp(player_facing, "E") == 0)
		angle = PI; // 180
	else
		angle = 0;
	return (angle);
}

void	rotate_player(t_data *data, int i)
{
	if (i == RIGHT)
	{
		data->player->angle += PLAYER_ROTATION_SPEED;
		if (data->player->angle > 2 * PI) // 2 * PI is a full circle in radians
			data->player->angle -= 2 * PI;
	}
	else if (i == LEFT)
	{
		data->player->angle -= PLAYER_ROTATION_SPEED;
		if (data->player->angle < 0)
			data->player->angle += 2 * PI;
	}
}

void	move_player(t_data *data, double move_x, double move_y)
{
	int	new_x;
	int	new_y;
	int	map_x;
	int	map_y;

	new_x = roundf(data->player->pos_x + move_x);
	new_y = roundf(data->player->pos_y + move_y);
	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (data->map[map_y][map_x] != 1 &&
		data->map[map_y][data->player->pos_x / TILE_SIZE] != 1 &&
		data->map[data->player->pos_y / TILE_SIZE][map_x] != 1)
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	hook_player_directions(t_data *data, double move_x, double move_y)
{
	if (data->player->rotation == RIGHT) //rotate right
		rotate_player(data, RIGHT);
	if (data->player->rotation == -1) //rotate left
		rotate_player(data, LEFT);
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
	if (data->player->horizontal == UP)
	{
		move_x = cos(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = sin(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	if (data->player->horizontal == DOWN)
	{
		move_x = -cos(data->player->angle) * PLAYER_MOVE_SPEED;
		move_y = -sin(data->player->angle) * PLAYER_MOVE_SPEED;
	}
	move_player(data, move_x, move_y);
}
