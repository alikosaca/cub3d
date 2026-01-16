/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/16 15:37:17 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	destroy_window(void *ptr)
{
	exit(cleanup((t_game *)ptr));
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
	else if (keycode == A)
		key->a = 1;
	else if (keycode == D)
		key->d = 1;
	else if (keycode == LOK)
		key->left = 1;
	else if (keycode == ROK)
		key->right = 1;
	return (0);
}

static int	keyrelease(int keycode, void *ptr)
{
	t_game	*game;
	t_keys	*key;

	game = (t_game *)ptr;
	key = &game->exec.key;
	if (keycode == W)
		key->w = 0;
	else if (keycode == S)
		key->s = 0;
	else if (keycode == A)
		key->a = 0;
	else if (keycode == D)
		key->d = 0;
	else if (keycode == LOK)
		key->left = 0;
	else if (keycode == ROK)
		key->right = 0;
	return (0);
}

static int	game_loop(void *ptr)
{
	t_game	*game;
	t_keys	*key;

	game = (t_game *)ptr;
	key = &game->exec.key;
	if (!(key->w || key->s || key->a || key->d || key->left || key->right))
		return (0);
	if (key->w)
		move_ws(&game->exec.ply, &game->pars.map, 1);
	if (key->s)
		move_ws(&game->exec.ply, &game->pars.map, -1);
	if (key->a)
		move_ad(&game->exec.ply, &game->pars.map, -1);
	if (key->d)
		move_ad(&game->exec.ply, &game->pars.map, 1);
	if (key->right)
		rotate_ply(&game->exec.ply, ROT_SPEED);
	if (key->left)
		rotate_ply(&game->exec.ply, -ROT_SPEED);
	ray_loop(&game->exec, &game->pars.map);
	mlx_put_image_to_window(game->exec.mlx.mlx, game->exec.mlx.win,
		game->exec.img.img, 0, 0);
	return (0);
}

void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_hook(win, 2, 1L << 0, keypress, game);
	mlx_hook(win, 3, 1L << 1, keyrelease, game);
	mlx_loop_hook(game->exec.mlx.mlx, game_loop, game);
}
