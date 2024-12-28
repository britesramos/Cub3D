/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/28 23:40:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	//Questions?
		//-How is the data structure going to look like?
	data = malloc(sizeof(t_data));
	if (!data)
		return (error_print_exit("Error\nFail to malloc data.\n", 1));
	if (argc == 2)
	{
		valid_map_extension_checker(argv[1]);
		init_data(data);
		if (!valid_map_file(argv[1], data))
			return (error_print_return("Error\nInvalid map file.\n", 1));
	//Execution
		//Raycasting.
	clean_up(data);
	//Clean_up.
	//Clean_up in case of error during program.
	}
	else
		printf("Error\nPlease provide a '*.cub' map.\n");
	return (0);
}
