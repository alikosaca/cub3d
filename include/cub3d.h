/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:29:37 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/08 19:24:50 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h> 

# include "errors.h"
# include "utils.h"
# include "parser.h"

typedef struct s_game
{
	t_parser	parser;
}	t_game;

void	verify(int argc, char *argv);
#endif
