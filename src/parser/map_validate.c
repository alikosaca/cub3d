/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:41:54 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/28 00:30:36 by yaycicek         ###   ########.fr       */
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

int	validate_map(t_map *map)
{
	if (check_map_tail(map->map, map->h - 1))
		return (1);
	return (0);
}
