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

void	init_player(t_data *input)
{
	input->player->pos_x = (input->player_sp_x * TILE_SIZE) + TILE_SIZE / 2;
	//divided by 2 so that the player is in the middle of a tile
	input->player->pos_y = (input->player_sp_y * TILE_SIZE) + TILE_SIZE / 2;
	input->player->fov_rad = (60 * PI) / 180;
	input->player->angle = facing_angle(input->player_facing);
	input->player->rotation = 0;
	input->player->horizontal = 0;
	input->player->vertical = 0;
	input->player->mm_pos_x = 0;
	input->player->mm_pos_y = 0;
}

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
	data->parse_utils->c_util = NULL;
	data->parse_utils->f_util = NULL;
}

void	init_data_helper(t_data *data)
{
	data->f_color = ft_calloc(sizeof(char *), 3 + 1);
	if (!data->f_color)
		error_print_exit(data, "Fail alloc f_color\n", -2);
	data->c_color = ft_calloc(sizeof(char *), 3 + 1);
	if (!data->c_color)
		error_print_exit(data, "Fail alloc c_color\n", -2);
	data->player_facing = ft_calloc(sizeof(char), 1 + 1);
	if (!data->player_facing)
		error_print_exit(data, "Fail alloc player_facing\n", -2);
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		error_print_exit(data, "Fail alloc player struct\n", -2);
	data->mlx_textures = malloc(sizeof(t_mlx_textures));
	if (!data->mlx_textures)
		error_print_exit(data, "Fail alloc mlx_textures\n", -2);
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		error_print_exit(data, "Fail alloc player\n", -2);
	data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		error_print_exit(data, "Fail alloc ray struct", -2);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->player_sp_x = 0;
	data->player_sp_y = 0;
	init_data_helper(data);
	init_parse_utils(data);
}
