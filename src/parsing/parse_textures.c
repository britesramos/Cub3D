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

static char	*add_texture_u(t_data *data, char *texture, char *str, char **file)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (get_i(str) == 1)
		i = 2;
	else if (get_i(str) == 2)
		i = 1;
	len = get_len(str, 2);
	while (is_space(str[i]))
		i++;
	texture = ft_calloc(sizeof(char), len + 1);
	if (!texture)
	{
		free_char_pointer_pointer(file);
		error_print_exit(data, "Error\nFail to alloc for new texture.\n", -1);
	}
	ft_strlcpy(texture, &str[i], len + 4);
	return (texture);
}

static void	add_texture_snew(t_data *data, char *str, int type, char **file)
{
	if (type == SO && data->parse_utils->so == false)
	{
		data->so = add_texture_u(data, data->so, str, file);
		data->parse_utils->so = true;
	}
	else if (type == NO && data->parse_utils->no == false)
	{
		data->no = add_texture_u(data, data->no, str, file);
		data->parse_utils->no = true;
	}
	else if (type == EA && data->parse_utils->ea == false)
	{
		data->ea = add_texture_u(data, data->ea, str, file);
		data->parse_utils->ea = true;
	}
	else if (type == WE && data->parse_utils->we == false)
	{
		data->we = add_texture_u(data, data->we, str, file);
		data->parse_utils->we = true;
	}
}

static void	add_texture_cf(t_data *data, char *str, int type, char **file)
{
	if (type == C && data->parse_utils->c == false)
	{
		data->parse_utils->c_util = add_texture_u(data,
				data->parse_utils->c_util, str, file);
		data->parse_utils->c = true;
	}
	else if (type == F && data->parse_utils->f == false)
	{
		data->parse_utils->f_util = add_texture_u(data,
				data->parse_utils->f_util, str, file);
		data->parse_utils->f = true;
	}
}

static void	add_texture_data(t_data *data, char *str, int type, char **file)
{
	int	len;

	len = 0;
	if ((type == C && data->parse_utils->c == true)
		|| (type == F && data->parse_utils->f == true)
		|| (type == SO && data->parse_utils->so == true)
		|| (type == NO && data->parse_utils->no == true)
		|| (type == EA && data->parse_utils->ea == true)
		|| (type == WE && data->parse_utils->we == true))
	{
		free_char_pointer_pointer(file);
		error_print_exit(data, "Duplicated texture\n", -1);
	}
	if (type == SO || type == NO || type == EA || type == WE)
		add_texture_snew(data, str, type, file);
	else if (type == C || type == F)
		add_texture_cf(data, str, type, file);
}

int	parse_textures(char **file, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		while (is_space(file[i][j]))
			j++;
		if (!ft_strncmp(&file[i][j], "SO", 2))
			add_texture_data(data, file[i], SO, file);
		else if (!ft_strncmp(&file[i][j], "NO", 2))
			add_texture_data(data, &file[i][j], NO, file);
		else if (!ft_strncmp(&file[i][j], "EA", 2))
			add_texture_data(data, file[i], EA, file);
		else if (!ft_strncmp(&file[i][j], "WE", 2))
			add_texture_data(data, file[i], WE, file);
		else if (!ft_strncmp(&file[i][j], "C", 1))
			add_texture_data(data, file[i], C, file);
		else if (!ft_strncmp(&file[i][j], "F", 1))
			add_texture_data(data, file[i], F, file);
		j = 0;
		i++;
	}
	return (1);
}
