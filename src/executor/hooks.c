/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/06 20:27:24 by akosaca          ###   ########.fr       */
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

static int	keypress(int keycode, void *ptr)
{
	t_game	*game;
	t_keys	*key;

	game = (t_game *)ptr;
	key = &game->exec.key;
	if (keycode == ESC)
		exit(cleanup(game));
	else if (keycode == W)
		key->w = 1;
	else if (keycode == S)
		key->s = 1;
	else if (keycode == LOK)
		key->left = 1;
	else if (keycode == ROK)
		key->right = 1;
	return (0);
}

static int	keyrelease(int keycode, void *ptr)
{
	t_keys	*key;

	key = (t_keys *)ptr;
	if (keycode == W)
		key->w = 0;
	else if (keycode == S)
		key->s = 0;
	else if (keycode == LOK)
		key->left = 0;
	else if (keycode == ROK)
		key->right = 0;
	return (0);
}

static void	move_ply(t_ply *ply, t_map *map, int dir)
{
	if (map->map[(int)ply->pos_y][(int)(ply->pos_x + ply->dir_x * MOVE_SPEED * dir)] != '1')
		ply->pos_x += ply->dir_x * MOVE_SPEED * dir;
	if (map->map[(int)(ply->pos_y + ply->dir_y * MOVE_SPEED * dir)][(int)ply->pos_x] != '1')
		ply->pos_y += ply->dir_y * MOVE_SPEED * dir;
}

static void	rotate_ply(t_ply *ply, double rot)
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

static int	game_loop(void *ptr)
{
	t_game	*game;
	t_keys	*key;
	int		moved;

	game = (t_game *)ptr;
	key = &game->exec.key;
	moved = 0;
	if (key->w || key->s || key->left || key->right)
		moved = 1;
	if (key->w)
		move_ply(&game->exec.ply, &game->pars.map, 1);
	if (key->s)
		move_ply(&game->exec.ply, &game->pars.map, -1);
	if (key->right)
		rotate_ply(&game->exec.ply, ROT_SPEED);
	if (key->left)
		rotate_ply(&game->exec.ply, -ROT_SPEED);
	if (moved)
	{
		ray_loop(&game->exec.ray, &game->exec.ply, &game->pars.map,
			&game->exec.img, &game->exec.xpm);
		mlx_put_image_to_window(game->exec.mlx.mlx, game->exec.mlx.win,
			game->exec.img.img, 0, 0);		
	}
	return (0);
}


void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_hook(win, 2, 1L<<0, keypress, game);
	mlx_hook(win, 3, 1L<<1, keyrelease, &game->exec.key);
	mlx_loop_hook(game->exec.mlx.mlx, game_loop, game);
}
