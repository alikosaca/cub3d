/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:22:39 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/24 12:59:10 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static int	set_rgb(t_pars *pars, char *lines[], int *out, int *count)
{
	if (!lines[1])
		return (print(ERR_MISS_RGB));
	if (lines[2])
		return (print(ERR_MULTI_RGB));
	if (set_rgb_values(pars, lines, out, count))
		return (1);
	return (0);
}

int	init_rgb(t_pars *pars, char *grid[], int i, int *count)
{
	static bool	initialized;
	int			out;
	int			checker;
	char		**lines;

	lines = get_split_lines(grid[i]);
	if (!lines)
		return (1);
	if (!initialized)
		init_rgb_values(&pars->fl, &pars->cl, &initialized);
	if (is_rgb(lines, &out))
	{
		checker = set_rgb(pars, lines, &out, count);
		if (checker == 1)
			return (__free((void ***)&lines), 1);
	}
	__free((void ***)&lines);
	return (0);
}
