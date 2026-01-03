/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:56:33 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/03 19:02:54 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	hit_dda(t_ray *ray, t_map *map)
{
	while (ray->hit == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side = EW;
			ray->map_x += ray->step_x;
			ray->side_dist_x += ray->delta_dist_x;
		}
		else
		{
			ray->side = NS;
			ray->map_y += ray->step_y;
			ray->side_dist_y += ray->delta_dist_y;
		}
		if (map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = true;
	}
}

// static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
// 		return ;
// 	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

static void	render_column(t_ray *ray, t_img *img, int x)
{
	int		y;
	int		color;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < ray->draw_start)
			color = 0x2b1b0e;
		else if (y <= ray->draw_end)
		{
			if (ray->side == NS)
				color = 0x703eb0;
			else if (ray->side == EW)
				color = 0xcf5f84;			
		}
		else
			color = 0x666666;
		my_mlx_pixel_put(img, x, y, color);
	}
}

static void	init_step_and_side_dist(t_ray *ray, t_ply *ply)
{
	int	res_x;
	int	res_y;

	res_x = 1;
	res_y = 1;
	if (ray->ray_dir_x < 0)
		res_x *= -1;
	if (ray->ray_dir_y < 0)
		res_y *= -1;
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (ply->pos_x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - ply->pos_x) * ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (ply->pos_y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - ply->pos_y) * ray->delta_dist_y;
	ray->step_x = res_x;
	ray->step_y = res_y;
}

static void	init_ray(t_ray *ray, t_ply *ply, int x)
{
	ray->map_x = (int)ply->pos_x;
	ray->map_y = (int)ply->pos_y;
	ray->hit = false;
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
	init_step_and_side_dist(ray, ply);
}

static void	wall_height(t_ray *ray, t_ply *ply)
{
	if (ray->side == EW)
		ray->perp_wall_dist = (ray->map_x - ply->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else if (ray->side == NS)
		ray->perp_wall_dist = (ray->map_y - ply->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->perp_wall_dist < 0.001)
		ray->line_height = SCREEN_HEIGHT;
	else
		ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
}

int	ray_loop(t_ray *ray, t_ply *ply, t_map *map, t_img *img)
{
	(void)img;
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(ray, ply, x);
		hit_dda(ray, map);
		wall_height(ray, ply);
		render_column(ray, img, x);
		x++;
	}
	
	return (0);
}
