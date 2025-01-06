/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:29 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/06 15:27:52 by sramos        ########   odam.nl         */
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

typedef struct s_parse_utils
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
}	t_parse_utils;

typedef	struct s_data
{
	t_parse_utils	*parse_utils;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_color;
	char	*c_color;
	int		player_sp_x;
	int		player_sp_y;
	char	*player_facing;
}	t_data;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;


void	init_data(t_data *data);

//------------INPUT CHECKER-------------//
void	valid_map_extension_checker(char *str);
void	valid_map_file(char *file, t_data *data);
int		valid_file_2d_array(char **file_2d_array, t_data *data);
int		new_line_middle_map(char *str);
int	valid_texture_rgb_checker(t_data *data);
//------------INPUT CHECKER UTILS-------//
int		is_space(char c);

//------------PARSING-------------------//
int		parse_textures(char **file_2d_array, t_data *data);
int		parse_map(char **file_2d_array, t_data *data);
int		valid_map(t_data *data);
int		no_limit(t_data *data);
char 	**flood_algorithm(char **map_flood, t_node *q);
t_node 	*create_node(t_node *q, int x, int y);

//------------ERROR EXIT---------------//
int		error_print_exit(t_data *data, char *str, int error);
int		error_print_return(char *str, int error); //

//------------CLEAN UP-----------------//
void	clean_up(t_data *data);
void	free_char_pointer(char *str);
void	free_char_pointer_pointer(char **str);

#endif