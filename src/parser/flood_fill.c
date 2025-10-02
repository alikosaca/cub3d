/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:17:55 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:54 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	has_open_neighbor(t_map *map, char **copy, int y, int x)
{
	if (is_out(y - 1, x, map->h, map->max_w) || is_space(copy[y - 1][x]))
		return (1);
	if (is_out(y + 1, x, map->h, map->max_w) || is_space(copy[y + 1][x]))
		return (1);
	if (is_out(y, x - 1, map->h, map->max_w) || is_space(copy[y][x - 1]))
		return (1);
	if (is_out(y, x + 1, map->h, map->max_w) || is_space(copy[y][x + 1]))
		return (1);
	return (0);
}

static int	check_open_edges(t_map *map, char *copy[])
{
	int	y;
	int	x;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->max_w)
		{
			if (is_walkable(copy[y][x]))
			{
				if (has_open_neighbor(map, copy, y, x))
					return (print(ERR_OPEN_MAP));
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	ff(t_map *map, char **copy, int y, int x)
{
	if (is_out(y, x, map->h, map->max_w))
		return ;
	if (is_space(copy[y][x]) || is_visited(copy[y][x]))
		return ;
	mark(&copy[y][x]);
	ff(map, copy, y - 1, x);
	ff(map, copy, y, x + 1);
	ff(map, copy, y + 1, x);
	ff(map, copy, y, x - 1);
}

static int	check_map_count(t_map *map, char *copy[])
{
	int	y;
	int	x;
	int	blocks;

	blocks = 0;
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->max_w)
		{
			if (!is_space(copy[y][x]) && !is_visited(copy[y][x]))
			{
				blocks++;
				if (blocks != 1)
					return (print(ERR_MULTI_MAP));
				ff(map, copy, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill(t_map *map, char *copy[])
{
	if (check_map_count(map, copy))
		return (1);
	if (check_open_edges(map, copy))
		return (1);
	return (0);
}
