/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/03 18:31:18 by akosaca          ###   ########.fr       */
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

static void	move_ply(int keycode, t_ply *ply, char **map)
{
	int	pos_x;
	int pos_y;
	int	dir;

	dir = 1;
	if (keycode == S)
		dir = -1;
	if (map[(int)ply->pos_y][(int)(ply->pos_x + ply->dir_x * MOVE_SPEED * dir)] != '1')
		ply->pos_x += ply->dir_x * MOVE_SPEED * dir;
	if (map[(int)(ply->pos_y + ply->dir_y * MOVE_SPEED * dir)][(int)ply->pos_x] != '1')
		ply->pos_y += ply->dir_y * MOVE_SPEED * dir;
}

static int	handle_key(int keycode, void *ptr)
{
	(void)ptr;
	if (keycode == ESC)
		exit(cleanup((t_game *)ptr));
	char	**map;
	void	*mlx;
	void	*win;
	t_ply	*ply;

	map = ((t_game *)ptr)->pars.map.map;
	mlx = ((t_game *)ptr)->exec.mlx.mlx;
	win = ((t_game *)ptr)->exec.mlx.win;
	ply = &((t_game *)ptr)->exec.ply;
	if (keycode == W || keycode == S)
		move_ply(keycode, ply, map);
	return (0);
}

void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_key_hook(win, handle_key, game);
}
