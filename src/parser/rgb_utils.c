/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:00:05 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/14 15:49:57 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_rgb_values(t_rgb *fl, t_rgb *cl, bool *initialized)
{
	fl->r = -1;
	fl->g = -1;
	fl->b = -1;
	cl->r = -1;
	cl->g = -1;
	cl->b = -1;
	(*initialized) = true;
}

static int	set_fl_or_cl(t_rgb *fl, t_rgb *cl, char **rgb_values, int *out)
{
	if ((*out) == 6 && (fl->r == -1 && fl->g == -1 && fl->b == -1))
	{
		fl->r = ft_atoi(rgb_values[0]);
		fl->g = ft_atoi(rgb_values[1]);
		fl->b = ft_atoi(rgb_values[2]);
		return (0);
	}
	else if ((*out) == 7 && (cl->r == -1 && cl->g == -1 && cl->b == -1))
	{
		cl->r = ft_atoi(rgb_values[0]);
		cl->g = ft_atoi(rgb_values[1]);
		cl->b = ft_atoi(rgb_values[2]);
		return (0);
	}
	else
		return (print(ERR_DUP_RGB));
}

static int	check_rgb_values(t_rgb *fl, t_rgb *cl, char **rgb_values, int *out)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_values[i])
	{
		j = 0;
		while (rgb_values[i][j])
		{
			if (!ft_isdigit(rgb_values[i][j]))
				return (print(ERR_RGB_NOT_NUM));
			j++;
		}
		if (ft_atoi(rgb_values[i]) < 0 || ft_atoi(rgb_values[i]) > 255)
			return (print(ERR_RGB_OUT_OF_RANGE));
		i++;
	}
	if (set_fl_or_cl(fl, cl, rgb_values, out))
		return (1);
	return (0);
}

int	set_rgb_values(t_rgb *fl, t_rgb *cl, char **lines, int *out)
{
	char	**rgb_values;

	rgb_values = ft_split(lines[1], ',');
	if (!rgb_values)
		return (1);
	if (lines[1][ft_strlen(lines[1]) - 1] == ',')
		return (__free((void ***)&rgb_values), print(ERR_TRAIL_COMMA_RGB));
	if (rgb_values[3])
		return (__free((void ***)&rgb_values), print(ERR_RGB_OVERFLOW));
	if (check_rgb_values(fl, cl, rgb_values, out))
		return (__free((void ***)&rgb_values), 1);
	__free((void ***)&rgb_values);
	return (0);
}
