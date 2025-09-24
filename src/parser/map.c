/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:20:08 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/24 21:13:50 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	init_map(t_pars *pars, char *grid[], int i)
{
	t_map	*map;

	map = &pars->map;
	if (set_map_height(&map->h, grid, i) < 3)
		return (print(ERR_MAP_TOO_SMALL));
	set_map_max_width(&map->max_w, grid, i);
	if (!__alloc((void ***)&map->map, map->h + 1, sizeof(char *)))
		return (1);
	if (!alloc_map_rows(&map->map, map->max_w + 1, map->h))
		return (1);
	if (fill_map(map, grid, i))
		return (1);
	return (0);
}
