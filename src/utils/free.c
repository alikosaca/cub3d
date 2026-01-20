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

void	_free(void **ptr)
{
	if (!(*ptr))
		return ;
	free((*ptr));
	(*ptr) = NULL;
}

void	__free(void ***ptr)
{
	size_t	i;

	if (!(*ptr))
		return ;
	i = 0;
	while ((*ptr)[i])
	{
		_free((void **)&(*ptr)[i]);
		i++;
	}
	free((*ptr));
	(*ptr) = NULL;
}
