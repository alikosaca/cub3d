/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:34:46 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/11 15:35:04 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "mlx.h"

typedef struct s_exec
{
	void	*mlx;
}	t_exec;

int	executor(t_exec *exec, t_pars *pars);
int	init_mlx(void **mlx);

#endif
