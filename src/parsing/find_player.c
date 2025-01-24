/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 10:44:18 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/23 19:34:03 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	get_player_data(t_data *data, char **map_flood, int i, int j)
{
	ft_strlcpy(data->player_facing, &map_flood[i][j], 2);
	data->player_sp_x = j;
	data->player_sp_y = i;
	data->player->pos_x = j;
	data->player->pos_y = i;
	data->map[i][j] = '0';
}

static t_node	*get_q(t_node *q, t_data *data, char **map_flood)
{
	q = create_node(q, data->player_sp_x, data->player_sp_y);
	if (!q)
	{
		free_char_pointer_pointer(map_flood);
		return (q);
	}
	return (q);
}

t_node	*find_player_position(t_data *data, t_node *q, char **map_flood)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				get_player_data(data, map_flood, i, j);
				map_flood[i][j] = 'X';
				q = get_q(q, data, map_flood);
				if (!q)
					break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (q);
}
