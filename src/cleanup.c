/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:00:05 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/21 15:47:26 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_game *game)
{
	destroy_pars(&game->pars);
	//void	close_game(t_exec **exec)
	//(*exec)->tex_path.ea
	if (game->exec.tex_path.ea)
		mlx_destroy_image(game->exec.mlx, game->exec.tex_path.ea);
	if (game->exec.tex_path.no)
		mlx_destroy_image(game->exec.mlx, game->exec.tex_path.no);
	if (game->exec.tex_path.so)
		mlx_destroy_image(game->exec.mlx, game->exec.tex_path.so);
	if (game->exec.tex_path.we)
		mlx_destroy_image(game->exec.mlx, game->exec.tex_path.we);
	if (game->exec.win)
		mlx_destroy_window(game->exec.mlx, game->exec.win);
	if (game->exec.mlx)
	{
		mlx_destroy_display(game->exec.mlx);
		_free(&game->exec.mlx);	
	}
	game->exec.tex_path.ea = NULL;
	game->exec.tex_path.no = NULL;
	game->exec.tex_path.so = NULL;
	game->exec.tex_path.we = NULL;
	game->exec.win = NULL;
}


