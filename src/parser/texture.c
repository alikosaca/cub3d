/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:24:01 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 06:06:04 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	is_tex(char **lines, int *out)
{
	if (!(*lines))
		return (0);
	if (ft_strcmp((*lines), "NO") == 0)
		(*out) = 1;
	else if (ft_strcmp((*lines), "SO") == 0)
		(*out) = 2;
	else if (ft_strcmp((*lines), "WE") == 0)
		(*out) = 3;
	else if (ft_strcmp((*lines), "EA") == 0)
		(*out) = 4;
	else
		(*out) = 0;
	return ((*out));
}

int	set_tex(t_pars *pars, char **lines, int *out)
{
	if (!lines[1])
		return (print(ERR_MISS_PATH));
	if (lines[2])
		return (print(ERR_MULTI_PATH));
	if ((*out) == 1 && !pars->tex.no)
		pars->tex.no = ft_strdup(lines[1]);
	else if ((*out) == 2 && !pars->tex.so)
		pars->tex.so = ft_strdup(lines[1]);
	else if ((*out) == 3 && !pars->tex.we)
		pars->tex.we = ft_strdup(lines[1]);
	else if ((*out) == 4 && !pars->tex.ea)
		pars->tex.ea = ft_strdup(lines[1]);
	else
		return (print(ERR_DUP_TEX));
	return (0);
}
