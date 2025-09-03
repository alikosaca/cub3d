/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:58:34 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/03 15:54:39 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "errors.h"

int		print(char *str);

void	*_alloc(void **ptr, size_t nmemb, size_t size);
void	*__alloc(void ***ptr, size_t nmemb, size_t size);
void	_free(void **ptr);
void	__free(void ***ptr);

#endif
