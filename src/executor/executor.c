/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/21 13:13:22 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_game(void **mlx)
{
	if (init_mlx(mlx))
		returen (1);
	return (0);
}

int	executor(t_exec *exec, t_pars *pars)
{
	(void)pars;
	if (init_game(&exec->mlx))
		return (1);
	mlx_destroy_display(exec->mlx);
	_free(&exec->mlx);
	return (0);
}
