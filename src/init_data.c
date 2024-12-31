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
}
