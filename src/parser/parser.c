/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:45:35 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/08 22:15:34 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	read_file(char ***grid, char *file)
{
	int		fd;
	int		height;

	if (!get_file_height(file, &fd, &height))
		return (print(ERR_EMPTY_MAP));
	if (!__alloc((void ***)grid, height + 1, sizeof(char *)))
		return (1);
	if (fill_grid(file, &fd, grid))
		return (1);
	return (0);
}

int	parser(t_pars *pars, char *file)
{
	char	**grid;

	(void)pars;
	grid = NULL;
	if (read_file(&grid, file))
		return (1);
	__free((void ***)&grid);
	return (0);
}
