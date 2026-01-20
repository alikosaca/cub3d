/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/10 00:10:00 by yaycicek         ###   ########.fr       */
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
