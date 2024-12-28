/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/27 13:52:33 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/27 13:52:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	all_textures_found(t_data *data)
{
	if (data->c_color == NULL)
		return (0);
	if (data->f_color == NULL)
		return (0);
	if (data->ea == NULL)
		return (0);
	if (data->no == NULL)
		return (0);
	if (data->so == NULL)
		return (0);
	if (data->we == NULL)
		return (0);
	return (1);
}

static char	*add_texture_utils(char *data_texture, char *str, int len)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	data_texture = ft_calloc(sizeof(char), len + 1);
	if (!data_texture)
	{
		printf("Fail to alloc data->so.\n");
		//exit_clean_up_function //TO DO.
	}
	ft_strlcpy(data_texture, &str[i], len);
	// printf("Texture: %s\n", data_texture);
	return (data_texture);
}

static int	get_len(char *str, int i)
{
	int	len;

	len = 0;
	while (is_space(str[i]))
		i++;
	while (str[i + len])
		len++;
	return (len);
}

static void	add_texture_data(t_data *data, char *str, int type)
{
	int	len;

	len = 0;
	if (type == SO || type == NO || type == EA || type == WE)
	{
		len = get_len(str, 2);
		if (type == SO)
			data->so = add_texture_utils(data->so, str, len);
		else if (type == NO)
			data->no = add_texture_utils(data->no, str, len);
		else if (type == EA)
			data->ea = add_texture_utils(data->ea, str, len);
		else if (type == WE)
			data->we = add_texture_utils(data->we, str, len);
	}
	else if (type == C || type == F)
	{
		len = get_len(str, 1);
		if (type == C)
			data->c_color = add_texture_utils(data->c_color, str, len);
		else if (type == F)
			data->f_color = add_texture_utils(data->f_color, str, len);
	}
}

int	parse_textures(char **file_2d_array, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file_2d_array[i])
	{
		while (is_space(file_2d_array[i][j]))
			j++;
		if (!ft_strncmp(&file_2d_array[i][j], "SO", 2))
			add_texture_data(data, file_2d_array[i], SO);
		else if (!ft_strncmp(&file_2d_array[i][j], "NO", 2))
			add_texture_data(data, &file_2d_array[i][j], NO);
		else if (!ft_strncmp(&file_2d_array[i][j], "EA", 2))
			add_texture_data(data, file_2d_array[i], EA);
		else if (!ft_strncmp(&file_2d_array[i][j], "WE", 2))
			add_texture_data(data, file_2d_array[i], WE);
		else if (!ft_strncmp(&file_2d_array[i][j], "C", 1))
			add_texture_data(data, file_2d_array[i], C);
		else if (!ft_strncmp(&file_2d_array[i][j], "F", 1))
			add_texture_data(data, file_2d_array[i], F);
		j = 0;
		i++;
	}
	if (!all_textures_found(data))
	{
		printf("Not all textures found!\n");
		return (0);
	}
	//Check if there is .png format.
	return (1);
}
