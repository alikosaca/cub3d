/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:41:20 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/02 16:25:59 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*is_walkable(char c)
{
	return (ft_strchr("0NSEW", c));
}

int	is_out(int y, int x, int h, int max_w)
{
	return (y < 0 || x < 0 || y >= h || x >= max_w);
}

int	is_space(char c)
{
	return (c == ' ');
}

int	is_visited(char c)
{
	return (c == 'M');
}

void	mark(char *c)
{
	(*c) = 'M';
}
