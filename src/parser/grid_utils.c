/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:29:39 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/16 16:41:19 by yaycicek         ###   ########.fr       */
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
		if (line[0] == '\n')
		{
			_free((void **)&line);
			continue ;
		}
		_free((void **)&line);
		(*height)++;
	}
	close(fd);
	return ((*height));
}

static int	strip_newline(char **line)
{
	int	j;

	j = 0;
	if ((*line)[j] == '\n')
		return (_free((void **)line), 1);
	while ((*line)[j])
	{
		if ((*line)[j] == '\n')
			(*line)[j] = '\0';
		j++;
	}
	return (0);
}

int	fill_grid(char **grid[], char *file, int fd)
{
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (strip_newline(&line))
			continue ;
		(*grid)[i] = ft_strdup(line);
		if (!(*grid)[i])
			return (_free((void **)&line), close(fd), 1);
		_free((void **)&line);
		i++;
	}
	(*grid)[i] = NULL;
	close(fd);
	return (0);
}

int	check_invalid_whitespace(char *grid[])
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (ft_isspace(grid[i][j]) && grid[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
