/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/18 12:55:45 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// #include <stdio.h>

// void	print_data(t_data *data)
// {
// 	if (!data)
// 	{
// 		printf("Error: t_data is NULL\n");
// 		return;
// 	}

// 	// Print string fields
// 	printf("North Texture (NO): %s\n", data->no);
// 	printf("South Texture (SO): %s\n", data->so);
// 	printf("West Texture (WE): %s\n", data->we);
// 	printf("East Texture (EA): %s\n", data->ea);
// 	printf("Floor Color (F): %s, %s, %s\n", data->f_color[0], data->f_color[1], data->f_color[2]);
// 	printf("Ceiling Color (C): %s, %s, %s\n", data->c_color[0], data->c_color[1], data->c_color[2]);

// 	// Print player information
// 	printf("Player Start Position (X, Y): (%d, %d)\n", data->player_sp_x, data->player_sp_y);
// 	printf("Player Facing Direction: %s\n", data->player_facing ? data->player_facing : "NULL");

// 	// Print the map
// 	if (data->map)
// 	{
// 		printf("Map:\n");
// 		for (int i = 0; data->map[i]; i++)
// 			printf("  %s\n", data->map[i]);
// 	}
// 	else
// 	{
// 		printf("Map: NULL\n");
// 	}

// 	// Print parse_utils if needed (assumes you have a print function for t_parse_utils)
// 	if (data->parse_utils)
// 		printf("Parse Utils: Available (Consider adding print function)\n");
// 	else
// 		printf("Parse Utils: NULL\n");

// 	// Print mlx_textures if needed (assumes you have a print function for t_mlx_textures)
// 	if (data->mlx_textures)
// 		printf("MLX Textures: Available (Consider adding print function)\n");
// 	else
// 		printf("MLX Textures: NULL\n");

// 	// Print MLX pointer
// 	printf("MLX Pointer: %s\n", data->mlx ? "Initialized" : "NULL");
// }

// void print_player(t_player *player)
// {
//     if (!player)
//     {
//         printf("Player structure is NULL.\n");
//         return;
//     }
//     printf("Player Details:\n");
//     printf("  Position X: %d\n", player->pos_x);
//     printf("  Position Y: %d\n", player->pos_y);
//     printf("  Angle (radians): %f\n", player->angle);
//     printf("  Field of View (radians): %f\n", player->fov_rad);
//     printf("  Rotation (radians): %f\n", player->rotation);
//     printf("  Horizontal Movement: %d\n", player->horizontal);
//     printf("  Vertical Movement: %d\n", player->vertical);
// }

// void print_texture_colors(t_mlx_textures *textures) {
//     if (!textures)
//         return;
        
//     // Print ceiling and floor colors in hexadecimal and decimal
//     printf("Ceiling color: 0x%08X (%u)\n", textures->ceiling, textures->ceiling);
//     printf("Floor color:   0x%08X (%u)\n", textures->floor, textures->floor);
// }

void	game_loop(void *data)
{
	t_data	*input;

	input = data;
	hook_player_directions(input, 0, 0);
	raycasting(input);
}

int	start_game(t_data *input)
{
	input->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!input->mlx)
		return (error_print_exit(input, "Failed to init window\n", -2));
	input->img = mlx_new_image(input->mlx, WIDTH, HEIGHT);
	if (!input->img)
		return (error_print_exit(input, "Fail init new image MLX42\n", -2));
	init_textures(input);
	mlx_image_to_window(input->mlx, input->img, 0, 0);
	// mini_map(input);
	// mlx_key_hook(input->mlx, key_actions_mm, input);
	mlx_key_hook(input->mlx, key_actions, input);
	mlx_loop_hook(input->mlx, &game_loop, input);
	mlx_loop(input->mlx);
	mlx_delete_image(input->mlx, input->img);
	mlx_terminate(input->mlx);
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
		valid_map_file(argv[1], data);
		init_player(data);
		start_game(data);
		mlx_terminate(data->mlx);
		clean_up(data);
	}
	else
		printf("Error\nPlease provide a valid map.\n");
	return (0);
}
