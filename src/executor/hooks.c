/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:42:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/18 13:49:37 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	destroy_window(void *ptr)
{
	exit(cleanup((t_game *)ptr));
}
static int	handle_key(int keycode, void *ptr)
{
	(void)ptr;
	printf("keycode:%d \n", keycode);
	// char	**in_map;
	// void	*in_mlx;
	// void	*in_win;
	// int		*i;
	// int		*j;

	// in_map = ((t_game *)ptr)->pars.map.map;
	// in_mlx = ((t_game *)ptr)->exec.mlx.mlx;
	// in_win = ((t_game *)ptr)->exec.mlx.win;
	// i = &(((t_game *)ptr)->pars.map.p_x);
	// j = &(((t_game *)ptr)->pars.map.p_y);
	// if (keycode == ESC)
	// 	exit(cleanup((t_game *)ptr));
	// if (keycode == W && ((t_game *)ptr)->pars.map.map[(*j)-1][*i] == '0')
	// {
	// 	in_map[(*j)-1][*i] = 'N';
	// 	in_map[*j][*i] = '0';
	// 	put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x000000);		
	// 	(*j)--;
	// 	put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x0000FF);	
	// }
	// else if (keycode == S && in_map[(*j)+1][(*i)] == '0')
	// {
	// 	in_map[(*j)+1][*i] = 'N';
	// 	in_map[*j][*i] = '0';
	// 	put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x000000);
	// 	(*j)++;
	// 	put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x0000FF);
	// }
	// else if (keycode == A)
	// {
	// 	if (in_map[*j][(*i)-1] == '0')
	// 	{
	// 		in_map[*j][(*i)-1] = 'N';
	// 		in_map[*j][(*i)] = '0';
	// 		put_window(in_mlx, in_win, ((*i) * 10), (*j * 10), 0x000000);
	// 		(*i)--;
	// 		put_window(in_mlx, in_win, ((*i) * 10), (*j * 10), 0x0000FF);			
	// 	}
	// }
	// else if (keycode == D)
	// {
	// 	if (in_map[(*j)][(*i)+1] == '0')
	// 	{
	// 		in_map[(*j)][(*i)+1] = 'N';
	// 		in_map[(*j)][(*i)] = '0';
	// 		put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x000000);
	// 		(*i)++;
	// 		put_window(in_mlx, in_win, ((*i) * 10), ((*j) * 10), 0x0000FF);
	// 	}
	// }
	// return (0);
}


void	init_hooks(t_game *game, void *win)
{
	mlx_hook(win, 17, 0, destroy_window, game);
	mlx_key_hook(win, handle_key, game);
}
