/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/12/21 11:06:08 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <math.h>
# include "mlx.h"
# include "parser.h"

# define PROJECT_NAME "cub3D"
// # define SCREEN_WIDTH 3840
// # define SCREEN_HEIGHT 2160
// # define SCREEN_WIDTH 1920
// # define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 190
# define SCREEN_HEIGHT 100

# define ESC 65307
# define A 97
# define W 119
# define S 115
# define D 100
# define LOK 65361
# define ROK 65363

typedef struct s_game	t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_xpm
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_xpm;

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
}	t_exec;

int		executor(t_game *game, t_exec *exec, t_pars *pars);

int		init_mlx(void **mlx);
int		create_xpm(void *mlx, t_xpm *xpm, t_tex tex);
int		create_win(void *mlx, void **win);
//int		read_map(void *mlx, void *win, t_map map);
int		init_img_data(t_img *img_data, void *mlx);

void	init_hooks(t_game *game, void *mlx);
void	destroy_exec(t_exec *exec);

void	draw_static_background(t_img *img);

int		ray_loop(t_exec *exec);

//void put_window(void *mlx, void *win, int x, int y, int color);
#endif
