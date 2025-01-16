/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/16 18:22:07 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#include <stdio.h>

void print_t_data(t_data *data)
{
	if (!data)
	{
		printf("Error: t_data is NULL\n");
		return;
	}

	// Print string fields
	printf("North Texture (NO): %s\n", data->no ? data->no : "NULL");
	printf("South Texture (SO): %s\n", data->so ? data->so : "NULL");
	printf("West Texture (WE): %s\n", data->we ? data->we : "NULL");
	printf("East Texture (EA): %s\n", data->ea ? data->ea : "NULL");
	printf("Floor Color (F): %s\n", data->f_color ? data->f_color : "NULL");
	printf("Ceiling Color (C): %s\n", data->c_color ? data->c_color : "NULL");

	// Print player information
	printf("Player Start Position (X, Y): (%d, %d)\n", data->player_sp_x, data->player_sp_y);
	printf("Player Facing Direction: %s\n", data->player_facing ? data->player_facing : "NULL");

	// Print the map
	if (data->map)
	{
		printf("Map:\n");
		for (int i = 0; data->map[i]; i++)
			printf("  %s\n", data->map[i]);
	}
	else
	{
		printf("Map: NULL\n");
	}

	// Print parse_utils if needed (assumes you have a print function for t_parse_utils)
	if (data->parse_utils)
		printf("Parse Utils: Available (Consider adding print function)\n");
	else
		printf("Parse Utils: NULL\n");

	// Print mlx_textures if needed (assumes you have a print function for t_mlx_textures)
	if (data->mlx_textures)
		printf("MLX Textures: Available (Consider adding print function)\n");
	else
		printf("MLX Textures: NULL\n");

	// Print MLX pointer
	printf("MLX Pointer: %s\n", data->mlx ? "Initialized" : "NULL");
}

int start_game(t_data *input)
{
	input->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!input->mlx)
		return (error_print_exit(input, "Failed to init window\n", -2));
	input->img = mlx_new_image(input->mlx, WIDTH, HEIGHT);
	if (!input->img)
		return (error_print_exit(input, "Failed to init imge to window\n", -2));
	init_player(input);
	return (0);
}



int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc == 2)
	{
		valid_map_extension_checker(argv[1]);
		data = malloc(sizeof(t_data));
		if (!data)
			return (error_print_exit(NULL, "Error\nFail to malloc data.\n", 1));
		init_data(data);
		valid_map_file(argv[1], data); //It is validating C and F withouth ','.
		// init_textures(data);
		// data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
		// if (!data->mlx)
		// 	return (error_print_exit(data, "Fail to init window!\n", -2));
		print_t_data(data);
		start_game(data);
		// mlx_key_hook(data->mlx, key_actions, &data); //TO DO - write key_actions.
		mlx_loop(data->mlx);
		//delete images.
		mlx_terminate(data->mlx);
		clean_up(data);
	}
	else
		printf("Error\nPlease provide a valid map.\n");
	return (0);
}
