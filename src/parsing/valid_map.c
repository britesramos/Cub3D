/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 23:52:26 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/28 23:52:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	odd_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	more_than_one_player(char **map)
{
	int		i;
	int		j;
	bool	player;

	i = 0;
	j = 0;
	player = false;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				&& player == true)
				return (1);
			if ((map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				&& player == false)
				player = true;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	no_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	valid_map(t_data *data)
{
	if (odd_characters(data->map))
		return (0);
	if (more_than_one_player(data->map))
		return (0);
	if (no_player(data->map))
		return (0);
	if (no_limit(data))
		return (0);
	return (1);
}
