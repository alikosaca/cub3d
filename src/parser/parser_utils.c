/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 06:19:21 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/24 14:52:09 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_identifier(char *line)
{
	while ((*line) == ' ')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (1);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (1);
	return (0);
}

int	is_mapline(char *line)
{
	while ((*line) == ' ')
		line++;
	while ((*line) && ft_strchr("01NSEW ", (*line)))
		line++;
	return ((*line) == '\0');
}
