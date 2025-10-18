/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:15:32 by akosaca           #+#    #+#             */
/*   Updated: 2025/10/18 16:03:50 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	put_color(t_img *img, int x, int y, int color)
{
	char	*addr;
	int		res;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
		return ;
	res = (y * img->line_length) + (x * (img->bpp/8));
	addr = img->addr + res;
	*(unsigned int*)addr = color;
}

void	draw_static_background(t_img *img)
{
	int	x;
	int	y;
	int cl;
	int ct;
	int sr_h;

	sr_h = SCREEN_HEIGHT / 2;
	cl	= sr_h - 250;
	ct	= sr_h + 250;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < cl)
				put_color(img, x, y, 0x228B22);
			else if (y > cl && y < ct)
				put_color(img, x, y, 0x000000);
			else
				put_color(img, x, y, 0x228B22);
			x++;
		}
		y++;
	}
}
