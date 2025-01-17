/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_rgb.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 11:02:56 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/17 11:03:49 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	valid_rgb(char *dig)
{
	int	value;
	int	i;

	value = 0;
	i = 1;
	while (dig[i])
	{
		if (dig[i] == '-')
			return (error_print_return("RGB value misconfiguration\n", 0));
		i++;
	}
	value = ft_atoi(dig);
	if (value < 0 || value > 255)
		return (error_print_return("RGB value misconfiguration\n", 0));
	return (1);
}

int	check_rgb(char **rgb_array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rgb_array[i])
	{
		while (rgb_array[i][j])
		{
			if (!ft_isdigit(rgb_array[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (rgb_array[i])
	{
		if (!valid_rgb(rgb_array[i]))
			return (0);
		i++;
	}
	return (1);
}
