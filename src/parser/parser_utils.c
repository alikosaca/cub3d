/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 06:19:21 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 06:19:28 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**get_split_lines(char *line)
{
	char	**lines;

	lines = ft_split(line, ' ');
	if (!lines)
		return (NULL);
	return (lines);
}
