/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_file.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 12:02:10 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/11 16:20:45 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	open_file(t_data *data, char *file, int fd)
{
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_print_exit(data, "Fail to open map file.\n", 0));
	return (fd);
}

static char	*realloc_str_file(t_data *data, char *str_file, int s_alloc, int fd)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_calloc(sizeof(char), ft_strlen(str_file) + 1);
	if (!tmp)
	{
		close(fd);
		error_print_exit(data, "Error alloc tmp in realloc.\n", -1);
	}
	ft_strlcpy(tmp, str_file, ft_strlen(str_file) + 1);
	free(str_file);
	str_file = NULL;
	str_file = ft_calloc(sizeof(char), s_alloc + 1);
	if (!str_file)
	{
		close(fd);
		free(tmp);
		error_print_exit(data, "Error realloc for str_file.\n", -1);
	}
	ft_strlcpy(str_file, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (str_file);
}

static char	*read_file(t_data *data, int fd)
{
	int		i;
	int		size_alloc;
	char	buf[1];
	char	*str_file;

	i = 0;
	size_alloc = 1;
	str_file = NULL;
	str_file = ft_calloc(sizeof(char), size_alloc + 1);
	if (!str_file)
	{
		close(fd);
		error_print_exit(data, "Fail to alloc for str_file.", -1);
	}
	while (read(fd, buf, 1) != 0)
	{
		if (i + 1 >= size_alloc)
		{
			size_alloc = size_alloc * 2;
			str_file = realloc_str_file(data, str_file, size_alloc, fd);
		}
		ft_strlcat(str_file, &buf[0], ft_strlen(str_file) + 2);
		i++;
	}
	return (str_file);
}

static char	**split_str_file(char *str_file)
{
	char	**file_2d_array;

	file_2d_array = NULL;
	file_2d_array = ft_split(str_file, '\n');
	free(str_file);
	str_file = NULL;
	return (file_2d_array);
}

void	valid_map_file(char *file, t_data *data)
{
	int		fd;
	char	*str_file;
	char	**file_2d_array;

	fd = 0;
	file_2d_array = NULL;
	fd = open_file(data, file, fd);
	str_file = read_file(data, fd);
	close(fd);
	if (new_line_middle_map(str_file) == 0)
	{
		free(str_file);
		error_print_exit(data, "Error\nNew line in the middle map.\n", -1);
	}
	file_2d_array = split_str_file(str_file);
	if (!file_2d_array)
		error_print_exit(data, "Error\nFail alloc file_2d_array\n", -1);
	if (!valid_file_2d_array(file_2d_array, data))
	{
		free_char_pointer_pointer(file_2d_array);
		error_print_exit(data, "Error\nINVALID MAP!\n", -1);
	}
	free_char_pointer_pointer(file_2d_array);
	printf("VALID MAP!\n");
}
