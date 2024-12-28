/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:29 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/29 00:23:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

typedef enum e_textures
{
	SO,
	NO,
	EA,
	WE,
	C,
	F,
}	t_textures_t;

typedef	struct s_data
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_color;
	char	*c_color;
	int		start_player_position_x;
	int		start_player_position_y;
}	t_data;

void	init_data(t_data *data);

//------------INPUT CHECKER-------------//
void	valid_map_extension_checker(char *str);
int		valid_map_file(char *file, t_data *data);
int		valid_file_2d_array(char **file_2d_array, t_data *data);
int		new_line_middle_map(char *str);
//------------INPUT CHECKER UTILS-------//
int		is_space(char c);

//------------PARSING-------------------//
int		parse_textures(char **file_2d_array, t_data *data);
int		parse_map(char **file_2d_array, t_data *data);
int		valid_map(char **map);


//------------ERROR EXIT---------------//
int		error_print_exit(char *str, int error);
int		error_print_return(char *str, int error);

//------------CLEAN UP-----------------//
void	clean_up(t_data *data);

#endif