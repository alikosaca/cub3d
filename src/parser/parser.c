/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:45:35 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/29 17:27:02 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	read_file(char **grid[], char *file)
{
	int	fd;
	int	height;

	fd = -1;
	if (!get_file_height(&height, file, fd))
		return (print(ERR_EMPTY_MAP));
	if (!__alloc((void ***)grid, height + 1, sizeof(char *)))
		return (1);
	if (fill_grid((*grid), file, fd))
		return (1);
	if (check_invalid_whitespace((*grid)))
		return (print(ERR_INVALID_WHITESPACE));
	return (0);
}

static int	check_file(char *grid[])
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		if (grid[i][0] == '\0')
			continue ;
		if (is_identifier(grid[i]))
			continue ;
		else if (is_mapline(grid[i]))
			continue ;
		else
			return (print(ERR_INVALID_LINE));
	}
	return (0);
}

static int	init_pars(t_pars *pars, char *grid[])
{
	int	c;
	int	i;

	c = 0;
	i = -1;
	while (grid[++i])
	{
		if (grid[i][0] == '\0')
			continue ;
		if (is_identifier(grid[i]))
		{
			if (init_tex(pars, grid, i, &c) || init_rgb(pars, grid, i, &c))
				return (1);
			continue ;
		}
		else if (is_mapline(grid[i]))
		{
			if (c != 6)
				return (print(ERR_PREMATURE_MAP));
			if (init_map(pars, grid, i))
				return (1);
			return (0);
		}
	}
	return (!(pars->map.map) && print(ERR_MISS_MAP));
}

int	parser(t_pars *pars, char *file)
{
	char	**grid;

	grid = NULL;
	if (read_file(&grid, file))
		return (__free((void ***)&grid), 1);
	if (check_file(grid))
		return (__free((void ***)&grid), 1);
	if (init_pars(pars, grid))
		return (__free((void ***)&grid), 1);
	if (validate_map(&pars->map))
		return (__free((void ***)&grid), 1);
	__free((void ***)&grid);
	return (0);
}
