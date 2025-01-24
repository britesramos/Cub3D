/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 15:51:42 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/24 16:38:55 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_textures_util(t_data *data, int type)
{
	mlx_texture_t	*tex;

	tex = NULL;

	if (type == SO)
	{
		tex = mlx_load_png(data->so);
		if (!tex)
		{
			//TO DO
			printf("There is no tex\n");
		}
		if (data->mlx_textures->so == NULL)
			printf("IT IS NULL!\n");
		data->mlx_textures->so = mlx_texture_to_image(data->mlx, tex);
		printf("HELLO!\n");
		if (!data->mlx_textures->so)
			return (0);
	}
	else if (type == NO)
	{
		tex = mlx_load_png(data->no);
		data->mlx_textures->no = mlx_texture_to_image(data->mlx, tex);
		if (!data->mlx_textures->no)
			return (0);
	}
	else if (type == WE)
	{
		tex = mlx_load_png(data->we);
		data->mlx_textures->we = mlx_texture_to_image(data->mlx, tex);
		if (!data->mlx_textures->we)
			return (0);
	}
	else if (type == EA)
	{
		tex = mlx_load_png(data->ea);
		data->mlx_textures->ea = mlx_texture_to_image(data->mlx, tex);
		if (!data->mlx_textures->ea)
			return (0);
	}
	mlx_delete_texture(tex);
	return (1);
}

// static void add_quotations(t_data *data)
// {
// 	char *res;

// 	res = NULL;
// 	res = ft_calloc(sizeof(char), 1 + 1);
// 	if (!res)
// 		error_print_exit(data, "Fail add_quotations - tex\n", -1);
	
	
// 	ft_strlcat()
// }

/*There is a segfault here somewhere.*/
void	init_textures(t_data *data)
{
	if (init_textures_util(data, SO) == 0)
		error_print_exit(data, "Fail tex to img : SO\n", -1);
	if (init_textures_util(data, NO) == 0)
		error_print_exit(data, "Fail tex to img : NO\n", -1);
	if (init_textures_util(data, EA) == 0)
		error_print_exit(data, "Fail tex to img : EA\n", -1);
	if (init_textures_util(data, WE) == 0)
		error_print_exit(data, "Fail tex to img : WE\n", -1);
}
