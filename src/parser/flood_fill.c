/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:17:55 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/07 20:05:10 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	has_open_neighbor(t_map *map, char *copy[], int y, int x)
{
	if (is_out(y - 1, x, map->h, map->max_w) || is_space(copy[y - 1][x]))
		return (1);
	if (is_out(y, x + 1, map->h, map->max_w) || is_space(copy[y][x + 1]))
		return (1);
	if (is_out(y + 1, x, map->h, map->max_w) || is_space(copy[y + 1][x]))
		return (1);
	if (is_out(y, x - 1, map->h, map->max_w) || is_space(copy[y][x - 1]))
		return (1);
	return (0);
}

static int	ff(t_map *map, char *copy[], int y, int x)
{
	if (is_out(y, x, map->h, map->max_w))
		return (0);
	if (is_space(copy[y][x]) || is_visited(copy[y][x]))
		return (0);
	if (!ft_strchr("10NSEW", copy[y][x]))
		return (0);
	if (is_walkable(copy[y][x]) && has_open_neighbor(map, copy, y, x))
		return (print(ERR_OPEN_MAP));
	mark(&copy[y][x]);
	if (ff(map, copy, y - 1, x))
		return (1);
	if (ff(map, copy, y, x + 1))
		return (1);
	if (ff(map, copy, y + 1, x))
		return (1);
	if (ff(map, copy, y, x - 1))
		return (1);
	return (0);
}

static int	check_remaining_map(t_map *map, char *copy[])
{
	int	y;
	int	x;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->max_w)
		{
			if (ft_strchr("10NSEW", copy[y][x]) && !is_visited(copy[y][x]))
				return (print(ERR_MULTI_MAP));
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill(t_map *map, char *copy[])
{
	if (ff(map, copy, map->p_y, map->p_x))
		return (1);
	if (check_remaining_map(map, copy))
		return (1);
	return (0);
}
