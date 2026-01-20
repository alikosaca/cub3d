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

int	validate_map(t_map *map)
{
	char	**copy;

	if (alloc_copy(&copy, map->map, map->h, map->max_w))
		return (1);
	if (flood_fill(map, copy))
		return (__free((void ***)&copy), 1);
	__free((void ***)&copy);
	return (0);
}
