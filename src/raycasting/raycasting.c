/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:56:33 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/13 14:40:18 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	draw_map(t_ray *ray, t_img *img, t_img *tex, int x, int tex_x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;
	int		tex_y;

	step = (double)tex->height / ray->line_height;
	tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < ray->draw_start)
			color = 0x2b1b0e;
		else if (y <= ray->draw_end)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			color = *(int *)(tex->addr + (tex_y * tex->line_length + tex_x * (tex->bpp / 8)));
		}
		else
			color = 0x666666;
		my_mlx_pixel_put(img, x, y, color);
	}
}

static	int	select_tex_x(t_ray *ray, t_ply *ply, t_img *tex)
{
	int		tex_x;
	double	wall_x;

	if (ray->side == EW)
		wall_x = ply->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ply->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * tex->width;
	if ((ray->side == EW && ray->ray_dir_x > 0)
		|| (ray->side == NS && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}


static t_img *select_tex(t_ray *ray, t_xpm *xpm)
{
	if (ray->side == NS)
	{
		if (ray->ray_dir_y > 0)
			return (&xpm->so);
		return (&xpm->no);
	}
	if (ray->side == EW)
	{
		if (ray->ray_dir_x > 0)
			return (&xpm->ea);
		return (&xpm->we);
	}
	return (NULL);
}

static void	render_column(t_ray *ray, t_img *img, int x, t_xpm *xpm, t_ply *ply)
{
	t_img	*tex;
	int		tex_x;

	tex = select_tex(ray, xpm);
	if (!tex || !tex->addr)
		return;
	tex_x = select_tex_x(ray, ply, tex);
	draw_map(ray, img, tex, x, tex_x);
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
	if (ray->line_height % 2 == 0)
        ray->draw_end--;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->line_height % 2 == 0)
        ray->draw_end--;

    if (ray->draw_end >= SCREEN_HEIGHT)
        ray->draw_end = SCREEN_HEIGHT - 1;
}

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

int	ray_loop(t_ray *ray, t_ply *ply, t_map *map, t_img *img, t_xpm *xpm)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(ray, ply, x);
		hit_dda(ray, map);
		wall_height(ray, ply);
		render_column(ray, img, x, xpm, ply);
		x++;
	}
	return (0);
}
