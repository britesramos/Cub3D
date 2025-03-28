/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 11:42:29 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/28 11:38:30 by rkaras        ########   odam.nl         */
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
# include <stdint.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64
# define PI 3.1415926535897932384626433

//------------PLAYER MOVES-------------//
# define LEFT -1
# define RIGHT 1
# define UP 1
# define DOWN -1
# define PLAYER_MOVE_SPEED 3
# define PLAYER_ROTATION_SPEED 0.05

# define VERTICAL 0
# define HORIZONTAL 1

//------------MINI-MAP-------------//
# define MM_TILE_SIZE 16
# define PLAYER_TILE_SIZE 8

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
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	uint32_t		floor;
	uint32_t		ceiling;
}	t_mlx_textures;

typedef struct s_player
{
	float			mm_pos_x;
	float			mm_pos_y;
	int				pos_x;
	int				pos_y;
	double			angle;
	double			fov_rad;
	double			rotation;
	int				horizontal;
	int				vertical;
}	t_player;

typedef struct s_ray
{
	double		ray_angle;
	double		wall_distance;
	int			intersection_type;
	double		horiz_x;
	double		horiz_y;
	double		vert_x;
	double		vert_y;
	int			slice;
}	t_ray;

typedef struct s_data
{
	t_parse_utils	*parse_utils;
	char			**map;
	int				map_width;
	int				map_height;
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
	t_ray			*ray;
}	t_data;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

void			init_data(t_data *data);

//------------INPUT CHECKER-------------//
void			valid_map_extension_checker(char *str);
void			valid_map_file(char *file, t_data *data);
int				valid_file_2d_array(char **file_2d_array, t_data *data);
int				new_line_middle_map(char *str);
int				valid_texture_rgb_checker(t_data *data);
int				check_rgb(char **rgb_array);
//------------INPUT CHECKER UTILS-------//
int				is_space(char c);

//------------PARSING-------------------//
int				parse_textures(char **file_2d_array, t_data *data);
int				get_i(char *str);
int				get_len(char *str, int i);
int				parse_map(char **file_2d_array, t_data *data);
int				valid_map(t_data *data);
int				no_limit(t_data *data);
char			**flood_algorithm(char **map_flood, t_node *q);
t_node			*create_node(t_node *q, int x, int y);
t_node			*find_player_position(t_data *data, t_node *q,
					char **map_flood);

//------------EXECUTION-------------------//
void			init_textures(t_data *data);
void			init_player(t_data *input);
double			facing_angle(char *player_facing);
void			rotate_player(t_data *data, int i);
void			move_player(t_data *data, double move_x, double move_y);
void			hook_player_directions(t_data *data, double move_x,
					double move_y);
void			raycasting(t_data *data);
double			get_v_inter(t_data *data, double angle);
double			get_h_inter(t_data *data, double angle);
int				wall_hit(double x, double y, t_data *data);
double			angle_check(double angle);
int				unit_circle(double angle, char ch);
int				inter_check(double angle, double *inter, double *step,
					int is_horizontal);
void			render_wall(t_data *data, int ray);
void			draw_ceiling_floor(t_data *data, int ray, int top_pixel,
					int bottom_pixel);
void			draw_walls(t_data *data, int top_pixel, int bottom_pixel,
					double wall_height);
double			get_x_offset(mlx_texture_t *texture, t_data *data);
mlx_texture_t	*get_texture(t_data *data, int int_type);
void			pixel_put(t_data *data, int x, int y, int color);


//------------MINI_MAP-------------------//
void	mini_map(t_data *data);

//------------KEY_ACTIONS-------------------//
void			key_actions(mlx_key_data_t keydata, void *param);
void			key_actions_mm(mlx_key_data_t keydata, void *param);

//------------ERROR EXIT---------------//
int				error_print_exit(t_data *data, char *str, int error);
int				error_print_return(char *str, int error); //

//------------CLEAN UP-----------------//
void			clean_up(t_data *data);
void			free_char_pointer(char *str);
void			free_char_pointer_pointer(char **str);

void			print_player(t_player *player);

#endif