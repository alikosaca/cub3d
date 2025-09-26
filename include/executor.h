/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/27 01:50:40 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "mlx.h"
# include "parser.h"

# define PROJECT_NAME "cub3D"
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define ESC 65307

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

typedef struct s_exec
{
	t_mlx	mlx;
	t_xpm	xpm;
}	t_exec;

int		executor(t_game *game, t_exec *exec, t_pars *pars);

int		init_mlx(void **mlx);
int		create_xpm(void *mlx, t_xpm *xpm, t_tex tex);
int		create_win(void *mlx, void **win);

void	init_hooks(t_game *game, void *mlx);

int		destroy_window(void *ptr);
int		destroy_window_with_esc(int keycode, void *ptr);

#endif
