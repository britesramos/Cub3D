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

//Need to save with direction player is facing.
static t_node	*find_player_position(t_data *data, t_node *q, char **map_flood)
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
				data->player_sp_x = j;
				data->player_sp_y = i;
				map_flood[i][j] = 'X';
				q = create_node(q, data->player_sp_x, data->player_sp_y);
				if (!q)
				{
					free_char_pointer_pointer(map_flood);
					error_print_exit(data, "Fail to alloc player node.\n", -1);
				}
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (q);
}

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
		error_print_exit(data, "Error\nFail to alloc map_flood\n", -1);
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
	if (map_flood == NULL)
		error_print_exit(data, "Error\nFail to cpy_map\n", -1);
	q = find_player_position(data, q, map_flood);
	map_flood = flood_algorithm(data, map_flood, q);
	if (!valid_map_flood(map_flood))
	{
		free_char_pointer_pointer(map_flood);
		return (1);
	}
	free_char_pointer_pointer(map_flood);
	return (0);
}
