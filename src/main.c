/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/23 19:11:15 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//TEMP
static void	print_data(t_data *data)
{
	if (data)
	{
		printf("no: %s\n", data->no);
		printf("so: %s\n", data->so);
		printf("we: %s\n", data->we);
		printf("ea: %s\n", data->ea);
		int	j = 0;
		while (data->c_color[j])
		{
			printf("c_color[%i]: %s\n", j, data->c_color[j]);
			j++;
		}
		j = 0;
		while (data->f_color[j])
		{
			printf("f_color[%i]: %s\n", j, data->f_color[j]);
			j++;
		}
		printf("player_sp_x: %i\n", data->player_sp_x);
		printf("player_sp_y: %i\n", data->player_sp_y);
		printf("player_fancing: %s\n", data->player_facing);
		int i = 0;
		while (data->map[i])
		{
			printf("Map[%i]: %s\n", i, data->map[i]);
			i++;
		}
	}
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
		print_data(data); //TEMP - DELETE THIS!
		data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
		if (!data->mlx)
			return (error_print_exit(data, "Fail to init window!\n", -2));
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		if (!data->img)
			return (error_print_exit(data, "Fail init new image MLX42\n", -2));
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		mini_map(data);
		init_textures(data);
		// start_game(data); //RENATA
		// mlx_key_hook(data->mlx, key_actions, &data);
		mlx_loop(data->mlx);
		delete_images(data);
		mlx_terminate(data->mlx);
		clean_up(data);
	}
	else
		printf("Error\nPlease provide a valid map.\n");
	return (0);
}
