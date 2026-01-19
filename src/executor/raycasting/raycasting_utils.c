/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:00:58 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/16 15:18:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	perp_wall_dist(t_ray *ray, t_ply *ply, int side)
{
	if (side == EW)
		return ((ray->map_x - ply->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x);
	else if (side == NS)
		return ((ray->map_y - ply->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y);
	return (ray->perp_wall_dist);
}

void	draw_map(t_game *game, t_img *tex, int x, int tex_x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		tex_y;
	int		y;

	step = (double)tex->height / game->exec.ray.line_height;;
	tex_pos = (game->exec.ray.draw_start - SCREEN_HEIGHT / 2
			+ game->exec.ray.line_height / 2) * step;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < game->exec.ray.draw_start)
			color = game->pars.cl.rgb;
		else if (y <= game->exec.ray.draw_end)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			color = *(int *)(tex->addr
					+ (tex_y * tex->line_length + tex_x * (tex->bpp / 8)));
		}
		else
			color = game->pars.fl.rgb;
		my_mlx_pixel_put(&game->exec.img, x, y, color);
	}
}

int	select_tex_x(t_ray *ray, t_ply *ply, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == EW)
		wall_x = ply->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ply->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * tex->width;
	if ((ray->side == EW && ray->ray_dir_x > 0)
		|| (ray->side == NS && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

t_img	*select_tex(t_ray *ray, t_xpm *xpm)
{
	if (ray->side == NS)
	{
		if (ray->ray_dir_y > 0)
			return (&xpm->so);
		return (&xpm->no);
	}
	if (ray->side == EW)
	{
		if (ray->ray_dir_x > 0)
			return (&xpm->ea);
		return (&xpm->we);
	}
	return (NULL);
}

void	init_step_and_side_dist(t_ray *ray, t_ply *ply)
{
	int	res_x;
	int	res_y;

	res_x = 1;
	res_y = 1;
	if (ray->ray_dir_x < 0)
		res_x *= -1;
	if (ray->ray_dir_y < 0)
		res_y *= -1;
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (ply->pos_x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - ply->pos_x) * ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (ply->pos_y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - ply->pos_y) * ray->delta_dist_y;
	ray->step_x = res_x;
	ray->step_y = res_y;
}
