/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:32:23 by akosaca           #+#    #+#             */
/*   Updated: 2025/10/15 11:32:21 by akosaca          ###   ########.fr       */
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

void put_window(void *mlx, void *win, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(mlx, win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	read_map(void *mlx, void *win, t_map map)
{
	(void)map;
	(void)win;
	(void)mlx;

	int i = 0;
	int j = 0;
	while (i < map.h)
	{
		j= 0;
		while (j < map.max_w)
		{
			printf("%c",map.map[i][j]);
			if (map.map[i][j] == '1')
				put_window(mlx, win, j * 10, i * 10, 0xFFFF00);
			else if (map.map[i][j] == '0')
				put_window(mlx, win, j * 10, i * 10, 0x000000);
			else if (map.map[i][j] == 'N')
				put_window(mlx, win, j * 10, i * 10, 0x0000FF);
			j++;
		}
		i++;
	}
	printf("\n");
	return (0);
}

