/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:00:05 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/27 01:10:04 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_game *game)
{
	destroy_pars(&game->pars);
	if (game->exec.xpm.no)
		mlx_destroy_image(game->exec.mlx.mlx, game->exec.xpm.no);
	if (game->exec.xpm.so)
		mlx_destroy_image(game->exec.mlx.mlx, game->exec.xpm.so);
	if (game->exec.xpm.we)
		mlx_destroy_image(game->exec.mlx.mlx, game->exec.xpm.we);
	if (game->exec.xpm.ea)
		mlx_destroy_image(game->exec.mlx.mlx, game->exec.xpm.ea);
	if (game->exec.mlx.win)
		mlx_destroy_window(game->exec.mlx.mlx, game->exec.mlx.win);
	if (game->exec.mlx.mlx)
	{
		mlx_destroy_display(game->exec.mlx.mlx);
		_free(&game->exec.mlx.mlx);
	}
}
