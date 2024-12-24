# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: marvin <marvin@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/11 11:43:31 by sramos        #+#    #+#                  #
#    Updated: 2024/12/24 20:53:53 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_PATH = src

SRC_FILES = src/main.c\
			src/valid_map_extension_checker.c\
			src/init_data.c\
			src/valid_map_file.c\
			src/new_line_middle_map.c\
			src/valid_file_2d_array.c\
			src/error_functions.c

OBJ_PATH = obj

OBJ_FILES = $(SRC_FILES:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

HEADER = include/cub3d.h

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
# CFLAGS += -fsanitize=address

RM = rm -f
RD = rm -rf

info-%:
	$(info $($*))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	@echo "SOURCE FILES COMPILED"
	make -C $(LIBFT_PATH)
	@echo "CREATING CUB3D"
	$(CC) $(OBJ_FILES) $(CFLAGS) $(OFLAGS) -o $(NAME) $(LIBFT)
	@echo "CUB3D CREATED"

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@if [ ! -d "$(@D)" ]; then mkdir $(@D) & echo "$(@D) MADE"; fi
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "REMOVING OBJECT FILES"
	$(RM) $(OBJ_FILES)
	$(RD) $(OBJ_PATH)
	@echo "OBJECT FILES REMOVED"

fclean: clean
	@echo "REMOVING CUB3D"
	$(RM) $(NAME)
	@echo "CUB3D REMOVED"

re: fclean all

.PHONY = all, clean, fclean, re, info