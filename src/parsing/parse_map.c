/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/27 17:18:27 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/27 17:18:27 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	alloc_data_map(t_data *data, char **file_2d_array)
{
	int	i;

	i = 6;
	while (file_2d_array[i])
		i++;
	data->map = ft_calloc(sizeof(char *), (i - 6) + 1);
	if (!data->map)
		return (error_print_return("Fail alloc data->map.\n", 0));
	return (1);
}

static int	parse_map2(t_data *data, char **file_2d_array)
{
	int	i;
	int	j;
	int	a;

	i = 6;
	j = 0;
	a = 0;
	while (file_2d_array[i])
	{
		while (file_2d_array[i][j])
			j++;
		data->map[a] = ft_calloc(sizeof(char), j + 1);
		if (!data->map[a])
			return (error_print_return("Fail to alloc string\n", 0));
		ft_strlcpy(data->map[a], file_2d_array[i], j + 1);
		j = 0;
		a++;
		i++;
	}
	return (1);
}

int	parse_map(char **file_2d_array, t_data *data)
{
	if (!alloc_data_map(data, file_2d_array))
		return (0);
	if (!parse_map2(data, file_2d_array))
		return (0);
	if (!valid_map(data))
		return (0);
	return (1);
}
