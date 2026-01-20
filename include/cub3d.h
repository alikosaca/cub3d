/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:29:37 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/27 01:54:49 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h> 

# include "errors.h"
# include "utils.h"
# include "parser.h"
# include "executor.h"

typedef struct s_game
{
	t_pars	pars;
	t_exec	exec;
}	t_game;

void	verify(int argc, char *argv);
int		cleanup(t_game *game);
#endif
