/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:29 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/17 15:08:13 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64
# define PI 3.1415926535897932384626433

//------------PLAYER MOVES-------------//
# define LEFT -1
# define RIGHT 1
# define UP 1
# define DOWN -1
# define PLAYER_MOVE_SPEED 5
# define PLAYER_TURN_SPEED 0.05

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
	char	*f_util;
	char	*c_util;
}	t_parse_utils;

typedef struct s_mlx_textures
{
	mlx_image_t	*no;
	mlx_image_t *so;
	mlx_image_t	*we;
	mlx_image_t *ea;
}	t_mlx_textures;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	double		angle;
	double		fov_rad;
	double		rotation;
	int			horizontal;
	int			vertical;
}	t_player;

typedef struct s_data
{
	t_parse_utils	*parse_utils;
	char			**map; //replace player with 0
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**f_color;
	char			**c_color;
	int				player_sp_x;
	int				player_sp_y;
	char			*player_facing;
	t_mlx_textures	*mlx_textures;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		*player;
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
int		valid_texture_rgb_checker(t_data *data);
int		check_rgb(char **rgb_array);
//------------INPUT CHECKER UTILS-------//
int		is_space(char c);

//------------PARSING-------------------//
int		parse_textures(char **file_2d_array, t_data *data);
int		get_i(char *str);
int		get_len(char *str, int i);
int		parse_map(char **file_2d_array, t_data *data);
int		valid_map(t_data *data);
int		no_limit(t_data *data);
char	**flood_algorithm(char **map_flood, t_node *q);
t_node	*create_node(t_node *q, int x, int y);
t_node	*find_player_position(t_data *data, t_node *q, char **map_flood);

//------------EXECUTION-------------------//
void	init_textures(t_data *data);
void	init_player(t_data *input);
double	facing_angle(char *player_facing);



//------------ERROR EXIT---------------//
int		error_print_exit(t_data *data, char *str, int error);
int		error_print_return(char *str, int error); //

//------------CLEAN UP-----------------//
void	clean_up(t_data *data);
void	free_char_pointer(char *str);
void	free_char_pointer_pointer(char **str);
void	delete_images(t_data *data);

#endif