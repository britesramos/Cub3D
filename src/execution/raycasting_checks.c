/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_checks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 14:28:15 by rkaras        #+#    #+#                 */
/*   Updated: 2025/03/28 15:13:44 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	angle_check(double angle)
{
	if (angle > 2 * PI)
		angle = angle - 2 * PI;
	if (angle < 0)
		angle = angle + 2 * PI;
	return (angle);
}

int	circle_check(double angle, char ch)
{
	if (ch == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (ch == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(double angle, double *inter, double *step, int is_horizontal)
{
	if (is_horizontal == HORIZONTAL)
	{
		if (angle > 0 && angle < PI)
		{
			*inter = *inter + TILE_SIZE;
			return (-1);
		}
		*step = *step * -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter = *inter + TILE_SIZE;
			return (-1);
		}
		*step = *step * -1;
	}
	return (1);
}
