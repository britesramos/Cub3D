/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 23:36:42 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/28 23:36:42 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_char_pointer(char *str)
{
	free(str);
	str = NULL;
}

void	free_char_pointer_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	clean_up(t_data *data)
{
	if (data->c_color)
		free_char_pointer(data->c_color);
	if (data->f_color)
		free_char_pointer(data->f_color);
	if (data->ea)
		free_char_pointer(data->ea);
	if (data->no)
		free_char_pointer(data->no);
	if (data->so)
		free_char_pointer(data->so);
	if (data->we)
		free_char_pointer(data->we);
	if (data->map)
		free_char_pointer_pointer(data->map);
	if (data)
		free(data);
}
