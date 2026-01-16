/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:32:23 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/16 15:43:10 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

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

int	init_img_data(t_img *img_data, void *mlx)
{
	img_data->img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img_data->img)
		return (print(ERR_CREATE_IMG));
	img_data->addr = mlx_get_data_addr(
			img_data->img,
			&img_data->bpp,
			&img_data->line_length,
			&img_data->endian);
	if (!img_data->addr)
		return (print(ERR_INIT_ADDR));
	return (0);
}

static void	init_ply_dir(t_ply *ply, char pos, int i, int j)
{
	int		sign;

	sign = 1;
	ply->pos_x = i + 0.5;
	ply->pos_y = j + 0.5;
	if (ft_strchr("NW", (int)pos))
		sign *= -1;
	if (ft_strchr("NS", (int)pos))
	{
		ply->dir_x = 0;
		ply->dir_y = 1 * sign;
		ply->plane_x = -0.66 * sign;
		ply->plane_y = 0;
	}
	if (ft_strchr("EW", (int)pos))
	{
		ply->dir_x = 1 * sign;
		ply->dir_y = 0;
		ply->plane_x = 0;
		ply->plane_y = 0.66 * sign;
	}
}

int	init_ply(t_ply *ply, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < map->h)
	{
		i = -1;
		while (++i < map->max_w)
		{
			if (ft_strchr("NEWS", map->map[j][i]))
			{
				init_ply_dir(ply, map->map[j][i], i, j);
				return (0);
			}
		}
	}
	return (0);
}
