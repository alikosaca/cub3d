/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:41:00 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/27 01:31:18 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game *const	game = &(t_game){0};

	verify(argc, argv[1]);
	if (parser(&game->pars, argv[1]))
		return (cleanup(game), EXIT_FAILURE);
	if (executor(game))
		return (cleanup(game), EXIT_FAILURE);
	cleanup(game);
	return (EXIT_SUCCESS);
}
