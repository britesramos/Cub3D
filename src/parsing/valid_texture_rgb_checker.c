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

// static int	digits_left(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	check_rgb_util(char *str, int j)
// {
// 	char	*dig;

// 	dig = NULL;
// 	dig = ft_calloc(sizeof(char), j + 1);
// 	if (!dig)
// 		return (error_print_return("Fail to alloc dig\n", 0));
// 	ft_strlcpy(dig, str, j + 1);
// 	if (!valid_rgb(dig))
// 	{
// 		free_char_pointer(dig);
// 		return (0);
// 	}
// 	free_char_pointer(dig);
// 	return (1);
// }

// static int	check_rgb(char **rgb_array)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (rgb_array[i] && digits_left(&rgb_array[i]))
// 	{
// 		while (!ft_isdigit(rgb_array[i]) && rgb_array[i] != '-')
// 			i++;
// 		if (rgb_array[i] == '-')
// 			j++;
// 		while (ft_isdigit(rgb_array[i + j]) || rgb_array[i + j] == '-')
// 			j++;
// 		if (!check_rgb_util(&rgb_array[i], j))
// 			return (0);
// 		i = i + j;
// 		j = 0;
// 	}
// 	return (1);
// }

static int	check_rgb(char **rgb_array)
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
static int	more_than_spaces_left(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	cpy_value_to_data(char **str, char **dst)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (str[i])
	{	
		while (is_space(str[i][j]) || str[i][j] == '0')
			j++;
		while (str[i][j + c] && !is_space(str[i][j + c]))
			c++;
		if (!more_than_spaces_left(&str[i][j + c])) //TO DO
			return (0);
		dst[i] = ft_calloc(sizeof(char), c + 1);
		// if (!dst[i])
			// return (-1);
		ft_strlcpy(dst[i], &str[i][j], c + 1);
		c = 0;
		j = 0;
		i++;
	}
	return (1);
}

static char **split_parse_utils(char *str)
{
	int		i;
	char	**ret;

	i = 0;
	ret = ft_split(str, ',');
	while(ret[i])
		i++;
	if (i != 3)
	{
		//free ret.
		return (NULL);
	}
	return (ret);
}

//coma at the end. and multiple commas at the end
//coma at begging. No fucking comas.
int	valid_texture_rgb_checker(t_data *data)
{
	char **split_c;
	char **split_f;

	//check if there are multiple consecutive ',' (comas with only spaces in between.)
	split_c = split_parse_utils(data->parse_utils->c_util);
	if (!split_c)
		return (0);
	split_f = split_parse_utils(data->parse_utils->f_util);
	if (!split_f)
		return (0);
	if (!cpy_value_to_data(split_c, data->c_color))
	{
		//free split_c
		return (0);
	}
	// free split_c
	if (!cpy_value_to_data(split_f, data->f_color))
	{
		//free split_f
		return (0);
	}
	//free split_f

	
	//check if values are only digits.
	//check if values are between 0-255.
	if (!check_rgb(data->c_color))
		return (0);
	if (!check_rgb(data->f_color))
		return (0);
	return (1);
}
