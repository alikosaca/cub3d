/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/10 17:13:49 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	destroy_window(void *ptr)
{
	exit(cleanup((t_game *)ptr));
}

static int	handle_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(cleanup(game));
	return (0);
}

void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_key_hook(win, handle_key, &game);
}
