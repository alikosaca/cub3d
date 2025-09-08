/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/08 18:28:48 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*_alloc(void **ptr, size_t nmemb, size_t size)
{
	if (!ptr)
		return (NULL);
	(*ptr) = ft_calloc(nmemb, size);
	if (!(*ptr))
		return (NULL);
	return ((*ptr));
}

void	*__alloc(void ***ptr, size_t nmemb, size_t size)
{
	if (!ptr)
		return (NULL);
	(*ptr) = ft_calloc(nmemb, size);
	if (!(*ptr))
		return (NULL);
	return ((*ptr));
}

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
