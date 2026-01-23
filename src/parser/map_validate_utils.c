/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:12:27 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 13:42:20 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	alloc_copy(char **copy[], char *map[], int h, int max_w)
{
	int	i;
	int	j;

	if (!__alloc((void ***)copy, h + 1, sizeof(char *)))
		return (1);
	i = 0;
	while (i < h)
	{
		if (!_alloc((void **)&(*copy)[i], max_w + 1, sizeof(char)))
			return (__free((void ***)copy));
		j = 0;
		while (j < max_w)
		{
			(*copy)[i][j] = map[i][j];
			j++;
		}
		(*copy)[i][j] = '\0';
		i++;
	}
	(*copy)[i] = NULL;
	return (0);
}
