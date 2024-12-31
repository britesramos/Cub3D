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

static void	valid_rgb(char *dig)
{
	int	value;
	int	i;

	value = 0;
	i = 1;
	while (dig[i])
	{
		if (dig[i] == '-')
			printf("ERROR\n");
		i++;
	}
	value = ft_atoi(dig);
	//Return error or exit program
	if (value < 0 || value > 255)
		printf("ERROR\n");
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

static void	check_rgb(t_data *data, char *str)
{
	int		i;
	int		j;
	int		dig_c;
	char	*dig;

	i = 0;
	j = 0;
	dig_c = 0;
	dig = NULL;
	while (str[i] && digits_left(&str[i]))
	{
		if (!str[i])
			error_print_exit(data, "Error\nMissing RGB value\n", -1);
		while (!ft_isdigit(str[i]) && str[i] != '-')
			i++;
		if (str[i] == '-')
			j++;
		while (ft_isdigit(str[i + j]) || str[i + j] == '-')
			j++;
		dig = ft_calloc(sizeof(char), j + 1);
		if (!dig)
			error_print_exit(data, "Error\nFail to alloc dig\n", -1);
		ft_strlcpy(dig, &str[i], j + 1);
		valid_rgb(dig);
		free_char_pointer(dig);
		i = i + j;
		j = 0;
		dig_c++;
	}
	if (dig_c != 3)
		printf("ERROR\nRGB value misconfiguration\n");
}

void	valid_texture_rgb_checker(t_data *data)
{
	check_rgb(data, data->c_color);
	check_rgb(data, data->f_color);
}
