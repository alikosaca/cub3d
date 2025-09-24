/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:24:01 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/24 12:58:57 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	is_tex(char **lines, int *out)
{
	if (!(*lines))
		return (0);
	if (ft_strcmp((*lines), "NO") == 0)
		(*out) = 2;
	else if (ft_strcmp((*lines), "SO") == 0)
		(*out) = 3;
	else if (ft_strcmp((*lines), "WE") == 0)
		(*out) = 4;
	else if (ft_strcmp((*lines), "EA") == 0)
		(*out) = 5;
	else
		(*out) = 0;
	return ((*out));
}

static int	set_tex(t_pars *pars, char **lines, int *out, int *count)
{
	t_tex	*tex;

	tex = &pars->tex;
	if (!lines[1])
		return (print(ERR_MISS_PATH));
	if (lines[2])
		return (print(ERR_MULTI_PATH));
	if ((*out) == 2 && !tex->no)
		tex->no = ft_strdup(lines[1]);
	else if ((*out) == 3 && !tex->so)
		tex->so = ft_strdup(lines[1]);
	else if ((*out) == 4 && !tex->we)
		tex->we = ft_strdup(lines[1]);
	else if ((*out) == 5 && !tex->ea)
		tex->ea = ft_strdup(lines[1]);
	else
		return (print(ERR_DUP_TEX));
	(*count)++;
	return ((*out));
}

int	init_tex(t_pars *pars, char *grid[], int i, int *count)
{
	int		out;
	int		checker;
	char	**lines;

	lines = get_split_lines(grid[i]);
	if (!lines)
		return (1);
	if (is_tex(lines, &out))
	{
		checker = set_tex(pars, lines, &out, count);
		if (checker == 1)
			return (__free((void ***)&lines), 1);
		if (is_xpm_file(&pars->tex, &out))
			return (__free((void ***)&lines), 1);
	}
	__free((void ***)&lines);
	return (0);
}
