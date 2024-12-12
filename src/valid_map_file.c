/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_file.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 12:02:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/12 12:08:04 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_map_file(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(error_print_exit("Fail to open map file.\n", 0));
	return (1);
}