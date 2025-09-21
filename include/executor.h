/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/21 14:13:40 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "mlx.h"

typedef struct s_exec
{
	void	*mlx;
	void	*win;
}	t_exec;



int	executor(t_exec *exec, t_pars *pars);
int	init_mlx(void **mlx);
int	create_win(void **mlx, void **win, int p_x, int p_y);

#endif
