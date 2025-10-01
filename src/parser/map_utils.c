/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:10 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:03 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	set_map_height(int *h, char *grid[], int i)
{
	while (grid[i])
	{
		(*h)++;
		i++;
	}
	return ((*h));
}

void	set_map_max_width(int *max_w, char *grid[], int i)
{
	int	len;
	int	max;

	max = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len > max)
			max = len;
		i++;
	}
	(*max_w) = max;
}

int	alloc_map(char **map[], int h, int max_w)
{
	int	i;

	if (!__alloc((void ***)map, h + 1, sizeof(char *)))
		return (1);
	i = 0;
	while (i < h)
	{
		if (!_alloc((void **)&(*map)[i], max_w + 1, sizeof(char)))
			return (1);
		i++;
	}
	return (0);
}

static int	set_player_info(t_map *map, int x, int y, char c)
{
	static int	initialized;

	if (!initialized)
	{
		map->p_x = -1;
		map->p_y = -1;
		initialized = true;
	}
	if (c == '\0')
		return ((map->p_x == -1 && map->p_y == -1) && print(ERR_NO_PLAYER));
	if (ft_strchr("NSEW", c))
	{
		if (map->p_x != -1 && map->p_y != -1)
			return (print(ERR_MULTI_PLAYER));
		map->p_x = x;
		map->p_y = y;
		map->p_dir = c;
		return (0);
	}
	return (0);
}

int	fill_map(t_map *map, char *grid[], int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->h)
	{
		k = 0;
		while (grid[i][k])
		{
			if (set_player_info(map, k, j, grid[i][k]))
				return (1);
			map->map[j][k] = grid[i][k];
			k++;
		}
		while (k < map->max_w)
		{
			map->map[j][k] = ' ';
			k++;
		}
		map->map[j][k] = '\0';
		i++;
		j++;
	}
	map->map[j] = NULL;
	return (set_player_info(map, -1, -1, '\0'));
}
