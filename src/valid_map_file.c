/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_file.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 12:02:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/27 13:46:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	open_file(char *file, int fd)
{
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_print_exit("Fail to open map file.\n", 0));
	return (fd);
}

static char	*realloc_str_file(char *str_file, int size_alloc)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_calloc(sizeof(char), ft_strlen(str_file) + 1);
	if (!tmp)
		error_print_exit("Error alloc tmp in realloc.\n", -1);
	ft_strlcpy(tmp, str_file, ft_strlen(str_file) + 1);
	free(str_file);
	str_file = NULL;
	str_file = ft_calloc(sizeof(char), size_alloc + 1);
	if (!str_file)
	{
		free(tmp);
		error_print_exit("Error realloc for str_file.\n", -1);
	}
	ft_strlcpy(str_file, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (str_file);
}

static char	*read_file(int fd)
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
		error_print_exit("Fail to alloc for str_file.", -1);
	while (read(fd, buf, 1) != 0)
	{
		if (i + 1 >= size_alloc)
		{
			size_alloc = size_alloc * 2;
			str_file = realloc_str_file(str_file, size_alloc);
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

int	valid_map_file(char *file, t_data *data)
{
	int		fd;
	char	*str_file;
	char	**file_2d_array;

	fd = 0;
	file_2d_array = NULL;
	fd = open_file(file, fd);
	str_file = read_file(fd);
	close(fd);
	if (new_line_middle_map(str_file) == 0)
	{
		free(str_file);
		return (0);
	}
	file_2d_array = split_str_file(str_file);
	if (!valid_file_2d_array(file_2d_array, data))
	{
		free(file_2d_array);
		file_2d_array = NULL;
		return (0);
	}
	free(file_2d_array);
	file_2d_array = NULL;
	return (1);
}
