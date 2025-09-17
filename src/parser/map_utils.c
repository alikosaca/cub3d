/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:10 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/17 14:15:46 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_map_height(int *height, char *grid[], int *i)
{
	int	j;

	j = (*i);
	while (grid[j])
	{
		(*height)++;
		j++;
	}
	return ((*height));
}

void	set_map_max_width(int *max_width, char *grid[], int *i)
{
	int	j;
	int	len;
	int	max;

	j = (*i);
	max = 0;
	while (grid[j])
	{
		len = ft_strlen(grid[j]);
		if (len > max)
			max = len;
		j++;
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

int	fill_map(t_map *map, char *grid[], int *i)
{
	int	j;
	int	k;
	int	len;

	j = 0;
	len = ft_strlen(grid[(*i)]);
	while (j < map->h)
	{
		k = 0;
		while (grid[(*i)][k])
		{
			map->map[j][k] = grid[(*i)][k];
			k++;
		}
		while (k < map->max_w)
		{
			map->map[j][k] = ' ';
			k++;
		}
		map->map[j][k] = '\0';
		(*i)++;
		j++;
	}
	map->map[j] = NULL;
	return (0);
}
