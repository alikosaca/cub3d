/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/26 15:03:52 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "mlx.h"

typedef struct s_tex_path
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_tex_path;

typedef struct s_exec
{
	void		*mlx;
	void		*win;
	t_tex_path	tex_path;
}	t_exec;

int	executor(t_exec *exec, t_pars *pars);
int	init_mlx(void **mlx);
int	create_win(void **mlx, void **win, int p_x, int p_y);
int	create_xpm(void *mlx, t_tex_path path, const t_tex *tex);

t_tex_path	init_tex_path();

#endif
