/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:45:35 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/11 18:07:34 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	read_file(char ***grid, char *file)
{
	int		fd;
	int		height;

	fd = -1;
	if (!get_file_height(&height, file, fd))
		return (print(ERR_EMPTY_MAP));
	if (!__alloc((void ***)grid, height + 1, sizeof(char *)))
		return (1);
	if (fill_grid(grid, file, fd))
		return (1);
	if (check_invalid_whitespace((*grid)))
		return (print(ERR_INVALID_WHITESPACE));
	return (0);
}

static int	init_pars(t_pars *pars, char **grid)
{
	int		i;
	int		out;
	char	**lines;

	i = 0;
	while (grid[i])
	{
		lines = get_split_lines(grid[i]);
		if (!lines)
			return (__free((void ***)&grid), 1);
		if (init_tex(pars, lines, &out))
			return (__free__((void ***)&grid, (void ***)&lines), 1);
		__free((void ***)&lines);
		i++;
	}
	return (0);
}

int	parser(t_pars *pars, char *file)
{
	char	**grid;

	(void)pars;
	grid = NULL;
	if (read_file(&grid, file))
		return (1);
	if (init_pars(pars, grid))
		return (1);
	__free((void ***)&grid);
	return (0);
}
