/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:42:55 by akosaca           #+#    #+#             */
/*   Updated: 2026/01/16 15:43:36 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	load_texture(void *mlx, t_img *tex_img, char *path)
{
	tex_img->img = mlx_xpm_file_to_image(mlx, path,
			&tex_img->width, &tex_img->height);
	if (!tex_img->img)
		return (1);
	tex_img->addr = mlx_get_data_addr(tex_img->img, &tex_img->bpp,
			&tex_img->line_length, &tex_img->endian);
	if (!tex_img->addr)
		return (1);
	return (0);
}

int	create_xpm(void *mlx, t_xpm *xpm, t_tex tex)
{
	if (load_texture(mlx, &xpm->no, tex.no)
		|| load_texture(mlx, &xpm->so, tex.so)
		|| load_texture(mlx, &xpm->we, tex.we)
		|| load_texture(mlx, &xpm->ea, tex.ea))
		return (print(ERR_CREATE_XPM));
	return (0);
}
