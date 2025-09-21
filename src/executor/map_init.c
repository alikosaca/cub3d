/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:32:23 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/21 13:39:46 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	init_mlx(void **mlx)
{
	(*mlx) = mlx_init();
	if (!(*mlx))
		return (1);
	return (0);
}

int	create_win(void **mlx, void **win, int p_x, int p_y)
{
	int	x_px;
	int	y_px;

	x_px = p_x * 64;
	y_px = p_y * 64;
	(*win) = mlx_new_window((*mlx), x_px, y_px, "cub3d");
	if (!(*win))
		return (1);
	return (0);
}
