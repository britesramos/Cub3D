/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 18:01:50 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/20 18:28:48 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0')
				mlx_put_pixel(data->img, x, y, 1);
			else if (data->map[y][x] == '1')
				mlx_put_pixel(data->img, x, y, 200);
			x++;
		}
		x = 0;
		y++;
	}
}

void	mini_map(t_data *data)
{
	init_map(data);
}
