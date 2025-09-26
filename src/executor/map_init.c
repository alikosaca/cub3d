/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:32:23 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/27 01:18:59 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <stdio.h>

int	init_mlx(void **mlx)
{
	(*mlx) = mlx_init();
	if (!(*mlx))
		return (print(ERR_CREATE_MLX));
	return (0);
}

int	create_win(void *mlx, void **win)
{
	(*win) = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, PROJECT_NAME);
	if (!(*win))
		return (print(ERR_OPEN_WIN));
	return (0);
}

int	create_xpm(void *mlx, t_xpm *xpm, t_tex tex)
{
	int	width;
	int	height;

	xpm->no = mlx_xpm_file_to_image(mlx, tex.no, &width, &height);
	xpm->so = mlx_xpm_file_to_image(mlx, tex.so, &width, &height);
	xpm->we = mlx_xpm_file_to_image(mlx, tex.we, &width, &height);
	xpm->ea = mlx_xpm_file_to_image(mlx, tex.ea, &width, &height);
	if (!xpm->ea || !xpm->no || !xpm->so || !xpm->we)
		return (print(ERR_CREATE_XPM));
	return (0);
}
