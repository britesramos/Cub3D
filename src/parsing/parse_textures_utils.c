/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 13:38:17 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/07 13:38:33 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_i(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) || str[i] == '	')
		i++;
	if (ft_strncmp(&str[i], "SO", 2))
		return (1);
	else if (ft_strncmp(&str[i], "NO", 2))
		return (1);
	else if (ft_strncmp(&str[i], "EA", 2))
		return (1);
	else if (ft_strncmp(&str[i], "WE", 2))
		return (1);
	else if (ft_strncmp(&str[i], "F", 1))
		return (2);
	else if (ft_strncmp(&str[i], "C", 1))
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
