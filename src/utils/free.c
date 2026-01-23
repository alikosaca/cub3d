/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:09:47 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 15:45:41 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_free(void **ptr)
{
	if (!(*ptr))
		return (1);
	free((*ptr));
	(*ptr) = NULL;
	return (1);
}

int	__free(void ***ptr)
{
	size_t	i;

	if (!(*ptr))
		return (1);
	i = 0;
	while ((*ptr)[i])
	{
		_free((void **)&(*ptr)[i]);
		i++;
	}
	free((*ptr));
	(*ptr) = NULL;
	return (1);
}
