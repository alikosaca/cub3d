/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/03 19:38:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	destroy_window(void *ptr)
{
	exit(cleanup((t_game *)ptr));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	move_ply(int keycode, t_ply *ply, t_map *map)
{
	int	dir;

	dir = 1;
	if (keycode == S)
		dir = -1;
	if (map->map[(int)ply->pos_y][(int)(ply->pos_x + ply->dir_x * MOVE_SPEED * dir)] != '1')
		ply->pos_x += ply->dir_x * MOVE_SPEED * dir;
	if (map->map[(int)(ply->pos_y + ply->dir_y * MOVE_SPEED * dir)][(int)ply->pos_x] != '1')
		ply->pos_y += ply->dir_y * MOVE_SPEED * dir;
}

static void	rotate_ply(int keycode, t_ply *ply)
{
    double	old_dir_x;
    double	old_plane_x;
    double	rot;

    rot = ROT_SPEED;
    if (keycode == ROK)
        rot *= -1;
    old_dir_x = ply->dir_x;
    ply->dir_x = ply->dir_x * cos(rot) - ply->dir_y * sin(rot);
    ply->dir_y = old_dir_x * sin(rot) + ply->dir_y * cos(rot);

    old_plane_x = ply->plane_x;
    ply->plane_x = ply->plane_x * cos(rot) - ply->plane_y * sin(rot);
    ply->plane_y = old_plane_x * sin(rot) + ply->plane_y * cos(rot);
}

static int	handle_key(int keycode, void *ptr)
{
	t_game	*game;
	t_ply	*ply;
	if (keycode == ESC)
		exit(cleanup((t_game *)ptr));

	game = (t_game *)ptr;
	ply = &game->exec.ply;
	if (keycode == W || keycode == S)
		move_ply(keycode, ply, &game->pars.map);
	if (keycode == LOK || keycode == ROK)
		rotate_ply(keycode, ply);
	ray_loop(&game->exec.ray, ply, &game->pars.map, &game->exec.img);
	mlx_put_image_to_window(game->exec.mlx.mlx, game->exec.mlx.win, game->exec.img.img, 0, 0);
	return (0);
}

void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_hook(win, 2, 1L<<0, handle_key, game);
}
