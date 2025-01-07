/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_limit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 16:40:15 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/30 16:40:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**cpy_map(t_data *data)
{
	int		i;
	char	**map_flood;

	i = 0;
	map_flood = NULL;
	while (data->map[i])
		i++;
	map_flood = ft_calloc(sizeof(char *), i + 1);
	if (!map_flood)
		return (map_flood);
	i = 0;
	while (data->map[i])
	{
		map_flood[i] = ft_strdup(data->map[i]);
		if (!map_flood[i])
		{
			while (i > 0)
			{
				free_char_pointer(map_flood[i]);
				i--;
			}
		}
		i++;
	}
	return (map_flood);
}

static int	x_on_limit(char **map_flood, int i, int j)
{
	int	rows;

	rows = 0;
	while (map_flood[rows])
		rows++;
	if (i + 1 >= rows)
		return (1);
	else if (i - 1 > 0 && map_flood[i - 1][j] != '1'
		&& map_flood[i - 1][j] != 'X')
		return (1);
	else if (map_flood[i + 1][j] != '1' && map_flood[i + 1][j] != 'X')
		return (1);
	else if (j - 1 > 0 && map_flood[i][j - 1] != '1'
		&& map_flood[i][j - 1] != 'X')
		return (1);
	else if (map_flood[i][j + 1] != '1' && map_flood[i][j + 1] != 'X')
		return (1);
	return (0);
}

static int	valid_map_flood(char **map_flood)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_flood[i])
	{
		while (map_flood[i][j])
		{
			if (map_flood[i][j] == 'X')
			{
				if (x_on_limit(map_flood, i, j))
				{
					printf("Map limit is not 1.\n");
					return (0);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	no_limit(t_data *data)
{
	t_node	*q;
	char	**map_flood;

	q = NULL;
	map_flood = cpy_map(data);
	if (!map_flood)
		return (error_print_return("Fail to cpy_map\n", 0));
	q = find_player_position(data, q, map_flood);
	if (!q)
		return (error_print_return("Couldn't find player position\n", 0));
	map_flood = flood_algorithm(map_flood, q);
	if (!map_flood)
		return (0);
	if (!valid_map_flood(map_flood))
	{
		free_char_pointer_pointer(map_flood);
		return (1);
	}
	free_char_pointer_pointer(map_flood);
	return (0);
}
