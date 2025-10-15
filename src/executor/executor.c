/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/10/14 16:56:23 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	init_game(t_exec *exec, t_pars *pars)
{
	if (init_mlx(&exec->mlx.mlx))
		return (1);
	if (create_xpm(exec->mlx.mlx, &exec->xpm, pars->tex))
		return (1);
	if (create_win(exec->mlx.mlx, &exec->mlx.win))
		return (1);
	if (read_map(exec->mlx.mlx, exec->mlx.win, pars->map))
		return (1);
	return (0);
}

int	executor(t_game *game, t_exec *exec, t_pars *pars)
{
	if (init_game(exec, pars))
		return (1);
	init_hooks(game, exec->mlx.win);
	mlx_loop(exec->mlx.mlx);
	return (0);
}
