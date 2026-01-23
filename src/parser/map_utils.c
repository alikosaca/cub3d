/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:10 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/05 20:01:15 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	fill_map(t_map *map, char *grid[], int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->h)
	{
		k = 0;
		while (grid[i][k])
		{
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
}

int	set_player_values(char *map[], int *p_y, int *p_x, char *p_dir)
{
	int	i;
	int	j;

	(*p_y) = -1;
	(*p_x) = -1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if ((*p_y) == -1 && (*p_x) == -1)
				{
					(*p_y) = i;
					(*p_x) = j;
					(*p_dir) = map[i][j];
				}
				else
					return (print(ERR_MULTI_PLAYER));
			}
		}
	}
	return (((*p_y) == -1 && (*p_x) == -1) && print(ERR_NO_PLAYER));
}
