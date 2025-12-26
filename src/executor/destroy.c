/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:46:12 by yaycicek          #+#    #+#             */
/*   Updated: 2025/12/26 18:09:49 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	destroy_xpm(void *mlx, t_xpm *xpm, void *img)
{
	if (xpm->no)
		mlx_destroy_image(mlx, xpm->no);
	if (xpm->so)
		mlx_destroy_image(mlx, xpm->so);
	if (xpm->we)
		mlx_destroy_image(mlx, xpm->we);
	if (xpm->ea)
		mlx_destroy_image(mlx, xpm->ea);
	if (img)
		mlx_destroy_image(mlx, img);
}

static void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		_free(&mlx->mlx);
	}
}

void	destroy_exec(t_exec *exec)
{
	destroy_xpm(exec->mlx.mlx, &exec->xpm, exec->img.img);
	destroy_mlx(&exec->mlx);
}
