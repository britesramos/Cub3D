/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 18:01:50 by sramos        #+#    #+#                 */
/*   Updated: 2025/02/14 14:56:28 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	draw_map(t_data *data)
{
	int				i;
	int				j;
	uint32_t		x;
	uint32_t		y;
	uint32_t		colour[2];

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	colour[0] = ft_my_pixel(0, 150, 255, 255);
	colour[1] = ft_my_pixel(6, 100, 255, 50);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			while (i < MM_TILE_SIZE)
			{
				while (j < MM_TILE_SIZE)
				{
					if (data->map[y][x] == '0')
						mlx_put_pixel(data->img, (x * MM_TILE_SIZE) + j, (y * MM_TILE_SIZE) + i, colour[1]);
					else if (data->map[y][x] == '1')
						mlx_put_pixel(data->img, (x * MM_TILE_SIZE) + j, (y * MM_TILE_SIZE) + i, colour[0]);
					j++;
				}
				j = 0;
				i++;
			}
			i = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_player(t_data *data)
{
	int				i;
	int				j;
	uint32_t		colour[1];

	i = 0;
	j = 0;
	colour[0] = ft_my_pixel(255, 0, 255, 255);
	while (i < PLAYER_TILE_SIZE)
	{
		while (j < PLAYER_TILE_SIZE)
		{
			mlx_put_pixel(data->img, (data->player->mm_pos_x * MM_TILE_SIZE) - (PLAYER_TILE_SIZE / 2) + j, (data->player->mm_pos_y * MM_TILE_SIZE) - (PLAYER_TILE_SIZE / 2) + i, colour[0]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	mini_map(t_data *data)
{
	draw_map(data);
	draw_player(data);
}
