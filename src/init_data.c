/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/24 19:52:31 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/24 19:52:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_parse_utils(t_data *data)
{
	data->parse_utils = malloc(sizeof(t_parse_utils));
	if (!data->parse_utils)
		error_print_exit(data, "Fail alloc parse_utils\n", -1);
	data->parse_utils->no = false;
	data->parse_utils->so = false;
	data->parse_utils->we = false;
	data->parse_utils->ea = false;
	data->parse_utils->f = false;
	data->parse_utils->c = false;
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f_color = NULL;
	data->c_color = NULL;
	data->player_sp_x = 0;
	data->player_sp_y = 0;
	data->player_facing = NULL;
	init_parse_utils(data);
}
