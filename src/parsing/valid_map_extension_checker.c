/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_extension_checker.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 11:54:25 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/07 14:07:37 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	more_than_cub(char *str)
{
	int	i;

	i = 4;
	if (str[i])
		return (1);
	return (0);
}

void	valid_map_extension_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".cub", 4) != 0
		|| (ft_strncmp(&str[i], ".cub", 4) == 0 && more_than_cub(&str[i])))
		error_print_exit(NULL, "Error\nPlease provide a valid map.\n", -1);
}
