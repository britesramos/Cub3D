/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/30 22:09:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	//Execution
		//Raycasting.
		clean_up(data);
	}
	else
		printf("Error\nPlease provide a '*.cub' map.\n");
	return (0);
}
