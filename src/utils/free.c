/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:09:47 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 04:42:20 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	_free(void **ptr)
{
	if (!ptr)
		return ;
	free((*ptr));
	(*ptr) = NULL;
}

void	__free(void ***ptr)
{
	size_t	i;

	if (!ptr)
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

void	_free_(void **f, void **s)
{
	_free(f);
	_free(s);
}

void	_free__(void **f, void ***s)
{
	_free(f);
	__free(s);
}

void	__free__(void ***f, void ***s)
{
	__free(f);
	__free(s);
}
