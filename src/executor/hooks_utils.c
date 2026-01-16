/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:15:32 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/16 15:34:05 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	rotate_ply(t_ply *ply, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ply->dir_x;
	ply->dir_x = ply->dir_x * cos(rot) - ply->dir_y * sin(rot);
	ply->dir_y = old_dir_x * sin(rot) + ply->dir_y * cos(rot);
	old_plane_x = ply->plane_x;
	ply->plane_x = ply->plane_x * cos(rot) - ply->plane_y * sin(rot);
	ply->plane_y = old_plane_x * sin(rot) + ply->plane_y * cos(rot);
}

void	move_ad(t_ply *ply, t_map *map, int dir)
{
	double	step;
	double	padding;
	double	next_x;
	double	next_y;

	step = MOVE_SPEED * dir;
	if (step > 0)
		padding = 0.2;
	else
		padding = -0.2;
	next_x = ply->pos_x + ply->plane_x * (step + padding);
	next_y = ply->pos_y + ply->plane_y * (step + padding);
	if (map->map[(int)ply->pos_y][(int)next_x] != '1')
		ply->pos_x += ply->plane_x * step;
	if (map->map[(int)next_y][(int)ply->pos_x] != '1')
		ply->pos_y += ply->plane_y * step;
}

void	move_ws(t_ply *ply, t_map *map, int dir)
{
	double	step;
	double	padding;
	double	next_x;
	double	next_y;

	step = MOVE_SPEED * dir;
	if (step > 0)
		padding = 0.2;
	else
		padding = -0.2;
	next_x = ply->pos_x + ply->dir_x * (step + padding);
	next_y = ply->pos_y + ply->dir_y * (step + padding);
	if (map->map[(int)ply->pos_y][(int)next_x] != '1')
		ply->pos_x += ply->dir_x * step;
	if (map->map[(int)next_y][(int)ply->pos_x] != '1')
		ply->pos_y += ply->dir_y * step;
}
