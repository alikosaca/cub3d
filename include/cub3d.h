/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:29:37 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 21:18:53 by akosaca          ###   ########.fr       */
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
}	t_game;

void	verify(int argc, char *argv);
void	cleanup(t_game *game);
#endif
