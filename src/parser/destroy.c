/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:01:53 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 05:05:42 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	destroy_tex(t_tex *tex)
{
	if (tex->no)
		_free((void **)&tex->no);
	if (tex->so)
		_free((void **)&tex->so);
	if (tex->we)
		_free((void **)&tex->we);
	if (tex->ea)
		_free((void **)&tex->ea);
}

static void	destroy_map(t_map *map)
{
	if (map->map)
		__free((void ***)&map->map);
}

void	destroy_pars(t_pars *pars)
{
	destroy_tex(&pars->tex);
	destroy_map(&pars->map);
}
