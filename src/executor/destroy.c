/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:46:12 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/04 16:32:26 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	destroy_xpm(void *mlx, t_xpm *xpm)
{
	if (xpm->no.img)
		mlx_destroy_image(mlx, xpm->no.img);
	if (xpm->so.img)
		mlx_destroy_image(mlx, xpm->so.img);
	if (xpm->we.img)
		mlx_destroy_image(mlx, xpm->we.img);
	if (xpm->ea.img)
		mlx_destroy_image(mlx, xpm->ea.img);
}

static void	destroy_img(void *mlx, void *img)
{
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
	destroy_xpm(exec->mlx.mlx, &exec->xpm);
	destroy_img(exec->mlx.mlx, exec->img.img);
	destroy_mlx(&exec->mlx);
}
