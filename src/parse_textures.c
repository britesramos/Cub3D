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

#include "../include/cub3d.h"

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

static void	add_texture_data(t_data *data, char *str, int type)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (type == SO)
	{
		i = 2;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->so = ft_calloc(sizeof(char), len + 1);
		if (!data->so)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->so, &str[i], len);
		printf("data->so: %s\n", data->so);
	}
	else if (type == NO)
	{
		i = 2;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->no = ft_calloc(sizeof(char), len + 1);
		if (!data->no)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->no, &str[i], len);
		printf("data->no: %s\n", data->no);
	}
	else if (type == EA)
	{
		i = 2;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->ea = ft_calloc(sizeof(char), len + 1);
		if (!data->ea)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->ea, &str[i], len);
		printf("data->ea: %s\n", data->ea);
	}
	else if (type == WE)
	{
		i = 2;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->we = ft_calloc(sizeof(char), len + 1);
		if (!data->we)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->we, &str[i], len);
		printf("data->we: %s\n", data->we);
	}
	else if (type == C)
	{
		i = 1;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->c_color = ft_calloc(sizeof(char), len + 1);
		if (!data->c_color)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->c_color, &str[i], len);
		printf("data->c_color: %s\n", data->c_color);
	}
	else if (type == F)
	{
		i = 1;
		while (is_space(str[i]))
			i++;
		while (str[i + len])
			len++;
		data->f_color = ft_calloc(sizeof(char), len + 1);
		if (!data->f_color)
		{
			printf("Fail to alloc data->so.\n");
			//exit_clean_up_function //TO DO.
		}
		ft_strlcpy(data->f_color, &str[i], len);
		printf("data->f_color: %s\n", data->f_color);
	}
	//TO DO.
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
	return (1);
}
