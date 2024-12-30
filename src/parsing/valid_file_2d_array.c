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

#include "../../include/cub3d.h"

int	valid_file_2d_array(char **file_2d_array, t_data *data)
{
	if (parse_textures(file_2d_array, data) == 0)
		return (0);
	if (parse_map(file_2d_array, data) == 0)
		return (0);
	return (1);
}
