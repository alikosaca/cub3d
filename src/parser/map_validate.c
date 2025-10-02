/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:41:54 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/02 16:22:49 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	verify_map(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10NSEW ", map[i][j]))
				return (print(ERR_INVALID_MAP_CHAR));
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map(t_map *map)
{
	char	**copy;

	if (verify_map(map->map))
		return (1);
	if (alloc_copy(&copy, map->map, map->h, map->max_w))
		return (1);
	if (flood_fill(map, copy))
		return (__free((void ***)&copy), 1);
	__free((void ***)&copy);
	return (0);
}
