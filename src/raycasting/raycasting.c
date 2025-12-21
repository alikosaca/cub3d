/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:56:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/12/21 11:10:07 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	init_ray(t_ray *ray, t_ply *ply, int x)
{
	ray->map_x = (int)ply->pos_x;
	ray->map_y = (int)ply->pos_y;
	ray->hit = 0;
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = ply->dir_x + ply->plane_x * ray->camera_x;
	ray->ray_dir_y = ply->dir_y + ply->plane_y * ray->camera_x;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

int	ray_loop(t_exec *exec)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(&exec->ray, &exec->ply, x);
		x++;
	}
	return (0);
}
