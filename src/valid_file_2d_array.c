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

// static void	print_array(char **file_2d_array)
// {
// 	int i = 0;
// 	while(file_2d_array[i])
// 	{
// 		printf("file_2d_array[%i]: %s\n", i, file_2d_array[i]);
// 		free(file_2d_array[i]);
// 		file_2d_array[i] = NULL;
// 		i++;
// 	}
// }

int	valid_file_2d_array(char **file_2d_array, t_data *data)
{
	// print_array(file_2d_array); //temp
	// int	i;
	// int	j;

	// i = 0;
	// j = 0;
	if (parse_textures(file_2d_array, data) == 0)
		return (0);
	//***PARSING MAP***//
	// i = 6;
	// while(file_2d_array[i])
	// 	j++;
	// data->map = ft_calloc(sizeof(char), j + 1);
	// if (!data->map)
	// 	error_print_exit("Map alloc failed.\n", 1);
	// while(file_2d_array[i])
	// {
	// 	j = 0;
	// 	while(file_2d_array[i][j])
	// 		j++;
		
	// }

	// 	if (map)
	// 		//check valid map.
	// 		//valid caracters.
	// 		//flood fill algorithm.

	//***PARSING MAP***//
	return (1);
}
