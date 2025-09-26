/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:24:51 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/27 01:55:53 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_window(void *ptr)
{
	exit(cleanup((t_game *)ptr));
}

int	destroy_window_with_esc(int keycode, void *ptr)
{
	if (keycode == ESC)
		exit(cleanup((t_game *)ptr));
	return (0);
}
