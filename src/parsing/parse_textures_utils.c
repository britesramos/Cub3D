/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 13:38:17 by sramos        #+#    #+#                 */
/*   Updated: 2025/03/31 12:28:38 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_i(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) || str[i] == '	')
		i++;
	if (ft_strncmp(&str[i], "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "EA", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "WE", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "F", 1) == 0)
		return (2);
	else if (ft_strncmp(&str[i], "C", 1) == 0)
		return (2);
	return (0);
}

int	get_len(char *str, int i)
{
	int	len;

	len = 0;
	while (is_space(str[i]) || str[i] == '	')
		i++;
	while (str[i + len])
		len++;
	return (len);
}

void	check_misconfig(t_data *data, char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
		i++;
	free_char_pointer_pointer(split);
	if (i > 2)
		error_print_exit(data, "Texture misconfiguration.\n", -1);
}

void	check_texture_name_duplicate(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(&str[i], "FF", 2) == 0)
		error_print_exit(data, "F texture misconfiguration.\n", -1);
	if (ft_strncmp(&str[i], "CC", 2) == 0)
		error_print_exit(data, "C texture misconfiguration.\n", -1);
	if (ft_strncmp(&str[i], "SOSO", 4) == 0
		|| ft_strncmp(&str[i], "SOS", 3) == 0)
		error_print_exit(data, "SO texture misconfiguration.\n", -1);
	if (ft_strncmp(&str[i], "WEWE", 4) == 0
		|| ft_strncmp(&str[i], "WEW", 3) == 0)
		error_print_exit(data, "WE texture misconfiguration.\n", -1);
	if (ft_strncmp(&str[i], "EAEA", 4) == 0
		|| ft_strncmp(&str[i], "EAE", 3) == 0)
		error_print_exit(data, "EA texture misconfiguration.\n", -1);
	if (ft_strncmp(&str[i], "NONO", 4) == 0
		|| ft_strncmp(&str[i], "NON", 3) == 0)
		error_print_exit(data, "NO texture misconfiguration.\n", -1);
}
