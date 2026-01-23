/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:20:08 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/05 20:00:28 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	init_map(t_pars *pars, char *grid[], int i)
{
	t_map	*map;

	map = &pars->map;
	if (set_map_height(&map->h, grid, i) < 3)
		return (print(ERR_MAP_TOO_SMALL));
	set_map_max_width(&map->max_w, grid, i);
	if (alloc_map(&map->map, map->h, map->max_w))
		return (1);
	fill_map(map, grid, i);
	if (set_player_values(map->map, &map->p_y, &map->p_x, &map->p_dir))
		return (1);
	return (0);
}
