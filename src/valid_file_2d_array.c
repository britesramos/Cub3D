/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_file_2d_array.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/24 00:36:31 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/24 00:36:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_file_2d_array(char **file_2d_array)
{
	int i = 0;
	while(file_2d_array[i])
	{
		printf("file_2d_array[%i]: %s\n", i, file_2d_array[i]);
		free(file_2d_array[i]);
		file_2d_array[i] = NULL;
		i++;
	}

	//Valid textures.
	//Valid F and C.
	//Valid Map (Flood fill algorithm).
	return (1);
}