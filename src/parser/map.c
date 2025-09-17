/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:20:08 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/17 13:18:16 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	init_map(t_pars *pars, t_map *map, char *grid[], int *i)
{
	(void)pars;
	if (!set_map_height(&map->h, grid, i))
		return (print(ERR_MISS_MAP));
	set_map_max_width(&map->max_w, grid, i);
	return (0);
}
