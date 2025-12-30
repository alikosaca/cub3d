/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/12/30 19:21:32 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "executor.h"
#include <stdio.h>

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
	// if (read_map(exec->mlx.mlx, exec->mlx.win, pars->map))
	// 	return (1);
	return (0);
}

int	executor(t_game *game, t_exec *exec, t_pars *pars)
{
	if (init_game(exec, pars))
		return (1);
	//draw_static_background(&exec->img);
	mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.win, exec->img.img, 0, 0);
	init_hooks(game, exec->mlx.win);
	if (ray_loop(&exec->ray, &exec->ply, &pars->map, &exec->img))
		return (1);
	mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.win, exec->img.img, 0, 0);
	mlx_loop(exec->mlx.mlx);
	return (0);
}
