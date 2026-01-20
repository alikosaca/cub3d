/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2026/01/20 16:16:28 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <math.h>
# include "mlx.h"
# include "parser.h"

# define PROJECT_NAME "cub3D"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MOVE_SPEED 0.04
# define ROT_SPEED 0.03

# define ESC 65307
# define A 97
# define W 119
# define S 115
# define D 100
# define LOK 65361
# define ROK 65363

# define NS 0
# define EW 1

typedef struct s_game	t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;	
}	t_keys;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_xpm
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}	t_xpm;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_ply;

typedef struct s_exec
{
	t_mlx	mlx;
	t_xpm	xpm;
	t_img	img;
	t_ray	ray;
	t_ply	ply;
	t_keys	key;
}	t_exec;

int		executor(t_game *game);

int		init_mlx(void **mlx);
int		create_win(void *mlx, void **win);
int		init_img_data(t_img *img_data, void *mlx);
int		init_ply(t_ply *ply, t_map *map);

int		create_xpm(void *mlx, t_xpm *xpm, t_tex tex);

void	init_hooks(t_game *game, void *mlx);

void	ray_loop(t_game *game, t_map *map);

void	init_step_and_side_dist(t_ray *ray, t_ply *ply);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

t_img	*select_tex(t_ray *ray, t_xpm *xpm);
void	init_step_and_side_dist(t_ray *ray, t_ply *ply);
int		select_tex_x(t_ray *ray, t_ply *ply, t_img *tex);

void	destroy_exec(t_exec *exec);

double	perp_wall_dist(t_ray *ray, t_ply *ply, int side);

void	draw_map(t_game *game, t_img *tex, int x, int tex_x);

void	rotate_ply(t_ply *ply, double rot);
void	move_ws(t_ply *ply, t_map *map, int dir);
void	move_ad(t_ply *ply, t_map *map, int dir);

#endif
