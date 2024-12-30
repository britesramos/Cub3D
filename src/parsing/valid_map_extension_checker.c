/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_extension_checker.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 11:54:25 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/30 16:02:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	valid_map_extension_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".cub", 4) != 0)
		error_print_exit(NULL, "Error\nInvalid map extension", -1);
}
