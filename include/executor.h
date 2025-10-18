/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/18 13:52:50 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "mlx.h"
# include "parser.h"

# define PROJECT_NAME "cub3D"
// # define SCREEN_WIDTH 3840
// # define SCREEN_HEIGHT 2160
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1000

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

typedef struct s_exec
{
	t_mlx	mlx;
	t_xpm	xpm;
	t_img	img;
}	t_exec;

int		executor(t_game *game, t_exec *exec, t_pars *pars);

int		init_mlx(void **mlx);
int		create_xpm(void *mlx, t_xpm *xpm, t_tex tex);
int		create_win(void *mlx, void **win);
int		read_map(void *mlx, void *win, t_map map);
int		init_img_data(t_img *img_data, void *mlx);

void	init_hooks(t_game *game, void *mlx);
void	destroy_exec(t_exec *exec);

//void	render_frame(t_exec *exec, t_pars *pars);



void put_window(void *mlx, void *win, int x, int y, int color);
#endif
