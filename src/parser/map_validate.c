/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:41:54 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 13:42:01 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	check_map_tail(char *map[], int end)
{
	int	i;

	i = 0;
	while (map[end][i])
	{
		if (map[end][i] != ' ')
			return (0);
		i++;
	}
	return (print(ERR_TRAIL_NL));
}

static int	check_map_duplicate_rows(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] != ' ')
				break ;
			j++;
		}
		if (map[i][j] == '\0')
			return (print(ERR_DUP_MAP_ROWS));
		i++;
	}
	return (0);
}

int	validate_map(t_map *map)
{
	char	**copy;

	if (check_map_tail(map->map, map->h - 1))
		return (1);
	if (check_map_duplicate_rows(map->map))
		return (1);
	if (alloc_copy(&copy, map->map, map->h, map->max_w))
		return (1);
	__free((void ***)&copy);
	return (0);
}
