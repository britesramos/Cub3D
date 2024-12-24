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

static int	all_textures_found(t_data *data)
{
	if (data->c_color == NULL)
		return (0);
	if (data->f_color == NULL)
		return (0);
	if (data->ea == NULL)
		return (0);
	if (data->no == NULL)
		return (0);
	if (data->so == NULL)
		return (0);
	if (data->we == NULL)
		return (0);
	return (1);
}

static void	add_texture_data(t_data *data, char *str, int type)
{
	if (type == SO)
		data->so = ft_strncpy()
	//TO DO.
}

int	valid_file_2d_array(char **file_2d_array, t_data *data)
{
	// print_array(file_2d_array); //temp
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(file_2d_array[i])
	{
		while (file_2d_array[i][j])
		{
			while (is_space(file_2d_array[i][j]))
				j++;
			// if (ft_strncmp(&file_2d_array[i][j], "SO", 2))
			// 	add_texture_data(data, file_2d_array[i], SO);
			if (ft_strncmp(&file_2d_array[i][j], "NO", 2))
				add_texture_data(data, &file_2d_array[i][j], NO);
			// else if (ft_strncmp(&file_2d_array[i][j], "EA", 2))
			// 	add_texture_data(data, file_2d_array[i], EA);
			// else if (ft_strncmp(&file_2d_array[i][j], "WE", 2))
			// 	add_texture_data(data, file_2d_array[i], WE);
			// else if (ft_strncmp(&file_2d_array[i][j], "C", 1))
			// 	add_texture_data(data, file_2d_array[i], C);
			// else if (ft_strncmp(&file_2d_array[i][j], "F", 2))
			// 	add_texture_data(data, file_2d_array[i], F);
			if (!all_textures_found(data))
				return (0);
		}
		// if (ft_strncmp(file_2d_array[i]))
		// while(file_2d_array[i][j])
		// {
		// 	if (textures)
		// 		//check valid texture.
		// 	if (C or F)
		// 		//check valid C or F.
		// 	if (map)
		// 		//check valid map.
		// 		//valid caracters.
		// 		//flood fill algorithm.
		// 	j++;
		// }
		// j = 0;
		i++;
	}
	//Do all textures exist?
	//Do C and F exist?

	//Valid textures.
	//Valid F and C.
	//Valid Map (Flood fill algorithm).
	return (1);
}
