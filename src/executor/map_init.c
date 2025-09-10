/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:32:23 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/10 21:32:26 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (1); //! add error message
	return (0);
}