/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:15:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/09/26 15:00:53 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
static int	init_game(t_exec *exec, t_pars *pars)
{

	exec->tex_path = (t_tex_path){0};
	if (init_mlx(&(exec->mlx)))
		return (1);
	if (create_xpm(exec->mlx, exec->tex_path, &pars->tex))
		return (1);
	return (0);
}

int	executor(t_exec *exec, t_pars *pars)
{
	if (init_game(exec, pars))
		return (1);
	return (0);
}
