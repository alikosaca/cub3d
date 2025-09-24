/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:10 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/24 20:55:18 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_map_height(int *height, char *grid[], int i)
{
	while (grid[i])
	{
		(*height)++;
		i++;
	}
	return ((*height));
}

void	set_map_max_width(int *max_width, char *grid[], int i)
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
	(*max_width) = max;
}

void	*alloc_map_rows(char **map[], int max_width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		(*map)[i] = _alloc((void **)&(*map)[i], max_width, sizeof(char));
		if (!(*map)[i])
			return (NULL);
		i++;
	}
	return ((void *)1);
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
	return (0);
}
