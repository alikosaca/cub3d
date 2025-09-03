/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:46:28 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/03 15:55:00 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define BOLD   "\e[1m"
#define RED    "\e[31m"
#define RESET  "\e[0m"

#define ERROR "Error"

int	print(char *str)
{
	ft_putstr_fd(BOLD, STDERR_FILENO);
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putendl_fd(RESET, STDERR_FILENO);
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}
