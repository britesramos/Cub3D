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

	i = 6;
	j = 0;
	while (file_2d_array[i + j])
		j++;
	data->map = ft_calloc(sizeof(char), j + 1);
	if (!data->map)
	{
		printf("Fail alloc data->map.\n");
		//error return function.
	}
	// 	if (map)
	// 		//check valid map.
	// 		//valid caracters.
	// 		//flood fill algorithm.
}
