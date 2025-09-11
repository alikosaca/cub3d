/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:22:39 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/11 21:41:33 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static void	init_rgb_values(t_rgb *fl, t_rgb *cl)
{
	fl->r = -1;
	fl->g = -1;
	fl->b = -1;
	cl->r = -1;
	cl->g = -1;
	cl->b = -1;
}

static int	is_rgb(char **lines, int *out)
{
	if (!(*lines))
		return (0);
	if (ft_strcmp((*lines), "F") == 0)
		(*out) = 6;
	else if (ft_strcmp((*lines), "C") == 0)
		(*out) = 7;
	else
		(*out) = 0;
	return ((*out));
}

static int	set_rgb_values(t_rgb *fl, t_rgb *cl, char **lines, int *out)
{
	char	**rgb_values;

	(void)fl;
	(void)cl;
	(void)out;
	rgb_values = ft_split(lines[1], ',');
	if (!rgb_values)
		return (1);
	if (rgb_values[3])
		return (__free((void ***)&rgb_values), print(ERR_RGB_OVERFLOW), 1);
	if (lines[1][ft_strlen(lines[1]) - 1])
		return (__free((void ***)&rgb_values), print(ERR_TRAIL_COMMA_RGB), 1);
	return (0);
}

static int	set_rgb(t_pars *pars, char **lines, int *out)
{
	if (!lines[1])
		return (print(ERR_MISS_RGB));
	if (lines[2])
		return (print(ERR_MULTI_RGB));
	if (set_rgb_values(&pars->fl, &pars->cl, lines, out))
		return (1);
	return (0);
}

int	init_rgb(t_pars *pars, char **lines, int *out)
{
	int	checker;

	init_rgb_values(&pars->fl, &pars->cl);
	if (is_rgb(lines, out))
	{
		checker = set_rgb(pars, lines, out);
		if (checker == 1)
			return (1);
	}
	return (0);
}
