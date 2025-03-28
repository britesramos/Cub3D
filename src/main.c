/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/28 10:32:53 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_loop(void *data)
{
	t_data	*input;

	input = data;
	hook_player_directions(input, 0, 0);
	raycasting(input);
	mini_map(input);
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
	mlx_key_hook(input->mlx, key_actions, input);
	// mlx_key_hook(input->mlx, key_actions_mm, input);
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
		// mlx_terminate(data->mlx);
		clean_up(data);
	}
	else
		printf("Error\nPlease provide a valid map.\n");
	return (0);
}
