/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 18:47:44 by rkaras        #+#    #+#                 */
/*   Updated: 2025/01/16 18:54:22 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	facing_angle(char *player_facing)
{
	double	angle;
	
	if (player_facing == 'N')
		angle = 3 * PI / 2;
	else if (player_facing == 'S')
		angle = PI / 2;
	else if (player_facing == 'E')
		angle = 0;
	else
		angle = PI;
	return (angle);
}