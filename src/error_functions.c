/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 11:56:00 by sramos        #+#    #+#                 */
/*   Updated: 2025/01/06 15:45:16 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	error_print_return(char *str, int error)
{
	printf("%s", str);
	return (error);
}

int	error_print_exit(t_data *data, char *str, int error)
{
	printf("%s", str);
	clean_up(data);
	exit (error);
}
