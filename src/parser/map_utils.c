/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:10 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/17 13:04:50 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_map_height(int *height, char *grid[], int *i)
{
	int	j;

	j = (*i);
	while (grid[j])
	{
		(*height)++;
		j++;
	}
	return ((*height));
}

void	set_map_max_width(int *max_width, char *grid[], int *i)
{
	int	j;
	int	len;
	int	max;

	j = (*i);
	max = 0;
	while (grid[j])
	{
		len = ft_strlen(grid[j]);
		if (len > max)
			max = len;
		j++;
	}
	(*max_width) = max;
}
