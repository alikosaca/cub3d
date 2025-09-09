/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:29:39 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 00:32:08 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	get_file_height(int *height, char *file, int fd)
{
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	(*height) = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		_free((void **)&line);
		(*height)++;
	}
	close(fd);
	return ((*height));
}

static void	strip_newline(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			(*line)[i] = '\0';
		i++;
	}
}

int	fill_grid(char ***grid, char *file, int fd)
{
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	i = -1;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		strip_newline(&line);
		(*grid)[++i] = ft_strdup(line);
		if (!(*grid)[i])
		{
			_free__((void **)&line, (void ***)grid);
			close(fd);
			return (1);
		}
		_free((void **)&line);
	}
	(*grid)[++i] = NULL;
	close(fd);
	return (0);
}

int	check_invalid_whitespace(char **grid)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			c = grid[i][j];
			if (ft_isspace(c) && c != ' ' && c != '\n')
			{
				__free((void ***)&grid);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
