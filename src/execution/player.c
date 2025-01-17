/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 18:47:44 by rkaras        #+#    #+#                 */
/*   Updated: 2025/01/17 14:47:57 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// convention (2d Cartesian angle system) is that the east position is 0 because it aligns with the x axis, and then we increase
// by 90 in clockwise direction

double	facing_angle(char *player_facing)
{
	double	angle;
	
	if (strcmp(player_facing, "N") == 0)
		angle = 3 * PI / 2; // 270
	else if (strcmp(player_facing, "S") == 0)
		angle = PI / 2; // 90
	else if (strcmp(player_facing, "E") == 0)
		angle = 0;
	else
		angle = PI; //180
	return (angle);
}