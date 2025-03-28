# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: marvin <marvin@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/11 11:43:31 by sramos        #+#    #+#                  #
#    Updated: 2025/03/27 16:17:10 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_PATH = src
MLXLIB = MLX42/build/libmlx42.a
LIBMLX = ./MLX42
FLAGSMLX = -ldl -lglfw -pthread -lm

SRC_FILES = src/main.c\
			src/init_data.c\
			src/parsing/valid_map_extension_checker.c\
			src/parsing/valid_map_file.c\
			src/parsing/new_line_middle_map.c\
			src/parsing/valid_file_2d_array.c\
			src/parsing/parse_textures.c\
			src/parsing/parse_textures_utils.c\
			src/parsing/parse_map.c\
			src/parsing/valid_map.c\
			src/parsing/no_limit.c\
			src/parsing/flood_algorithm.c\
			src/parsing/valid_texture_rgb_checker.c\
			src/parsing/check_rgb.c\
			src/parsing/find_player.c\
			src/parsing/init_textures.c\
			src/execution/mini_map.c\
			src/execution/key_actions_mm.c\
			src/execution/key_actions.c\
			src/execution/player.c\
			src/execution/raycasting.c\
			src/execution/raycasting_utils.c\
			src/execution/rendering.c\
			src/execution/walls.c\
			src/error_functions.c\
			src/clean_up.c


OBJ_PATH = obj

OBJ_FILES = $(SRC_FILES:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

HEADER = include/cub3d.h

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
# CFLAGS += -fsanitize=address

MLXFLAGS = -ldl -lglfw -lm -lpthread
MLX42_PATH = ./MLX42/build
MLX42 = $(MLX42_PATH)/libmlx42.a

RM = rm -f
RD = rm -rf

info-%:
	$(info $($*))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_FILES) $(HEADER)
	@echo "SOURCE FILES COMPILED"
	make -C $(LIBFT_PATH)
	make -C $(MLX42_PATH)
	@echo "CREATING CUB3D"
	$(CC) $(OBJ_FILES) $(CFLAGS) $(OFLAGS) -o $(NAME) $(LIBFT) $(MLX42) $(MLXFLAGS)
	@echo "CUB3D CREATED"

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@if [ ! -d "$(@D)" ]; then mkdir $(@D) & echo "$(@D) MADE"; fi
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "REMOVING OBJECT FILES"
	@$(MAKE) clean -C ./libft
	$(RM) $(OBJ_FILES)
	$(RD) $(OBJ_PATH)
	$(RD) $(LIBMLX)/build
	@echo "OBJECT FILES REMOVED"

fclean: clean
	@echo "REMOVING CUB3D"
	@$(MAKE) fclean -C $ ./libft
	$(RM) $(NAME)
	@echo "CUB3D REMOVED"

re: fclean all

.PHONY = all, clean, fclean, re, info