/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:46:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 15:50:37 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define ERROR "\e[1m\e[31mError\e[0m"

int	print(char *str)
{
	ft_putendl_fd(ERROR, STDERR_FILENO);
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}
