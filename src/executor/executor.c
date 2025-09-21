/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/21 15:04:21 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_game(t_exec **exec, t_pars *pars)
{
	int x_line;
	int y_line;

	x_line = pars->map.max_w;
	y_line = pars->map.h;
	if (init_mlx(&(*exec)->mlx))
		return (1);
	if (create_win(&(*exec)->mlx, &(*exec)->win, x_line, y_line))
		return (1);
	if (create_xpm((*exec)->mlx, &(*exec)->tex_path))
		return (1);
	return (0);
}

int	executor(t_exec *exec, t_pars *pars)
{
	if (init_game(&exec, pars))
		return (1);
	if (exec->win)
		mlx_destroy_window(exec->mlx, exec->win);
	if (exec->mlx)
	{
		mlx_destroy_display(exec->mlx);
		_free(&exec->mlx);	
	}
	exec->win = NULL;
	return (0);
}
