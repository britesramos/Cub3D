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

static int	is_one(char *map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		if (map[j] != '1' && map[j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

static int	first_last_ones(char **map)
{
	int	i;

	i = 0;
	if (!is_one(map[i]))
		return (0);
	while (map[i])
		i++;
	i--;
	if (!is_one(map[i]))
		return (0);
	return (1);
}

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
		while(map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') && player == true)
				return (1);
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') && player == false)
				player = true;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	valid_map(char **map)
{
	if (!first_last_ones(map))
		return (0);
	if (odd_characters(map))
		return (0);
	if (more_than_one_player(map))
		return (0);
	//Do not found player.
	//flood algorithm.
	//
	//found player position.
	//must be surrounded by walls.
	//doesnt need to have a valid path as so_long.
	return (1);
}
