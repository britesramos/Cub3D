/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_algorithm.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 20:00:11 by anonymous     #+#    #+#                 */
/*   Updated: 2024/12/30 20:00:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_node	*create_node(t_node *q, int x, int y)
{
	t_node	*n_node;

	n_node = (t_node *)malloc(sizeof(t_node));
	if (!n_node)
	{
		while (q)
		{
			free(q);
			q = NULL;
			q = q->next;
		}
		return (NULL);
	}
	n_node->x = x;
	n_node->y = y;
	n_node->next = NULL;
	return (n_node);
}

static	t_node	*add_node_set_x(t_node *q, char **map_flood, int y, int x)
{
	t_node	*current;

	current = q;
	while (current->next)
		current = current->next;
	current->next = create_node(q, x, y);
	if (!current->next)
	{
		free_char_pointer_pointer(map_flood);
		return (0);
	}
	map_flood[y][x] = 'X';
	return (q);
}

static t_node	*remove_node(t_node *q)
{
	t_node	*to_free;

	to_free = q;
	q = q->next;
	free(to_free);
	to_free = NULL;
	return (q);
}

char	**flood_algorithm(char **map_flood, t_node *q)
{
	int	rows;

	rows = 0;
	while (map_flood[rows])
		rows++;
	while (q)
	{
		if (q->y - 1 > 0 && map_flood[q->y - 1][q->x] == '0')
			q = add_node_set_x(q, map_flood, q->y - 1, q->x);
		if (q->y + 1 < rows && map_flood[q->y + 1][q->x] == '0')
			q = add_node_set_x(q, map_flood, q->y + 1, q->x);
		if (q->x - 1 > 0 && map_flood[q->y][q->x - 1] == '0')
			q = add_node_set_x(q, map_flood, q->y, q->x - 1);
		if (map_flood[q->y][q->x + 1] == '0')
			q = add_node_set_x(q, map_flood, q->y, q->x + 1);
		q = remove_node (q);
	}
	return (map_flood);
}
