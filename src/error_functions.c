/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_print_exit.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 11:56:00 by sramos        #+#    #+#                 */
/*   Updated: 2024/12/12 12:08:56 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	error_print_return(char *str, int error)
{
	printf("%s", str);
	return (error);
}

int	error_print_exit(char *str, int error)
{
	printf("%s", str);
	exit (error);
}
