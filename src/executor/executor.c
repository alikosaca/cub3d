/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/16 15:24:41 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_game(t_exec *exec, t_pars *pars)
{
	if (init_mlx(&exec->mlx.mlx))
		return (1);
	if (create_xpm(exec->mlx.mlx, &exec->xpm, pars->tex))
		return (1);
	if (create_win(exec->mlx.mlx, &exec->mlx.win))
		return (1);
	if (init_img_data(&exec->img, exec->mlx.mlx))
		return (1);
	if (init_ply(&exec->ply, &pars->map))
		return (1);
	return (0);
}

int	executor(t_game *game)
{
	t_pars	*pars;
	t_exec	*exec;

	pars = &game->pars;
	exec = &game->exec;
	if (init_game(exec, pars))
		return (1);
	mlx_put_image_to_window(exec->mlx.mlx,
		exec->mlx.win, exec->img.img, 0, 0);
	if (ray_loop(game, &pars->map))
		return (1);
	init_hooks(game, exec->mlx.win);
	mlx_put_image_to_window(exec->mlx.mlx,
		exec->mlx.win, exec->img.img, 0, 0);
	mlx_loop(exec->mlx.mlx);
	return (0);
}
