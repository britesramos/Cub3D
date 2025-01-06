/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_texture_rgb_checker.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/31 14:10:07 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/31 14:10:07 by anonymous     ########   odam.nl         */
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

static int	digits_left(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_rgb_util(char *str, int j)
{
	char	*dig;

	dig = NULL;
	dig = ft_calloc(sizeof(char), j + 1);
	if (!dig)
		return (error_print_return("Fail to alloc dig\n", 0));
	ft_strlcpy(dig, str, j + 1);
	if (!valid_rgb(dig))
	{
		free_char_pointer(dig);
		return (0);
	}
	free_char_pointer(dig);
	return (1);
}

static int	check_rgb(char *str)
{
	int		i;
	int		j;
	int		dig_c;

	i = 0;
	j = 0;
	dig_c = 0;
	while (str[i] && digits_left(&str[i]))
	{
		while (!ft_isdigit(str[i]) && str[i] != '-')
			i++;
		if (str[i] == '-')
			j++;
		while (ft_isdigit(str[i + j]) || str[i + j] == '-')
			j++;
		if (!check_rgb_util(&str[i], j))
			return (0);
		i = i + j;
		j = 0;
		dig_c++;
	}
	if (dig_c != 3)
		return (error_print_return("RGB value misconfiguration\n", 0));
	return (1);
}

int	valid_texture_rgb_checker(t_data *data)
{
	if (!check_rgb(data->c_color))
		return (0);
	if (!check_rgb(data->f_color))
		return (0);
	return (1);
}
