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

int	parse_map(char **file_2d_array, t_data *data)
{
	int	i;
	int	j;
	int	a;

	i = 6;
	j = 0;
	a = 0;
	while (file_2d_array[i + j])
		j++;
	data->map = ft_calloc(sizeof(char), (j - 6) + 1);
	if (!data->map)
	{
		printf("Fail alloc data->map.\n");
		//error return function.
	}
	j = 0;
	while (file_2d_array[i])
	{
		while (file_2d_array[i][j])
			j++;
		data->map[a] = ft_calloc(sizeof(char), j + 1);
		if (!data->map[a])
		{
			printf("Fail alloc data->map[%i].\n", a);
			//error return funtion.
		}
		ft_strlcpy(data->map[a], file_2d_array[i], j + 1);
		j = 0;
		a++;
		i++;
	}
	i = 0;
	j = 0;
	while (i <= 8)
	{
		while(data->map[i][j])
		{
			write(1, &data->map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		j = 0;
		i++;
	}
	// 	if (map)
	// 		//check valid map.
	// 		//valid caracters.
	// 		//flood fill algorithm.
	return (1);
}
