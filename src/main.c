/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:06 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/12 12:11:50 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	//Questions?
		//-How do the maps look like?
		//-How is the data structure going to look like?
	if (argc == 2)
	{
		valid_map_extension_checker(argv[1]);
		if (!valid_map_file(argv[1]))
			return (error_print_return("Error\nInvalid map file.\n", 1));
	//Execution
		//Raycasting.
	//Clean_up.
	//Clean_up in case of error during program.
	}
	else
		printf("Error\nPlease provide a '*.cub' map.\n");
	return (0);
}