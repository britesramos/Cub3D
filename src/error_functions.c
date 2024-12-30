/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 11:56:00 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/30 16:12:02 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Needed?
int	error_print_return(t_data *data, char *str, int error)
{
	printf("%s", str);
	clean_up(data);
	return (error);
}

int	error_print_exit(t_data *data, char *str, int error)
{
	printf("%s", str);
	clean_up(data);
	exit (error);
}
