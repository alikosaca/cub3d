/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:00:05 by yaycicek          #+#    #+#             */
/*   Updated: 2025/12/06 12:20:27 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_rgb(int r, int b, int g)
{
	return (r << 16 | g << 8 | b);
}

static int	validate_rgb_commas(char *definition)
{
	char	*comma;

	if (definition[0] == ',')
		return (print(ERR_RGB_START_WITH_COMMA));
	else if (definition[ft_strlen(definition) - 1] == ',')
		return (print(ERR_TRAIL_COMMA_RGB));
	comma = ft_strchr(definition, ',');
	while (comma)
	{
		if (comma[-1] == ',' || comma[1] == ',')
			return (print(ERR_INVALID_RGB_FORMAT));
		comma = ft_strchr(comma + 1, ',');
	}
	return (0);
}

static int	set_fl_or_cl(t_pars *pars, char **rgb_values, int *out, int *count)
{
	t_rgb	*fl;
	t_rgb	*cl;

	fl = &pars->fl;
	cl = &pars->cl;
	if ((*out) == 6 && (fl->r == -1 && fl->g == -1 && fl->b == -1))
	{
		fl->r = ft_atoi(rgb_values[0]);
		fl->g = ft_atoi(rgb_values[1]);
		fl->b = ft_atoi(rgb_values[2]);
		fl->rgb = create_rgb(fl->r, fl->g, fl->b);
		(*count)++;
		return (0);
	}
	else if ((*out) == 7 && (cl->r == -1 && cl->g == -1 && cl->b == -1))
	{
		cl->r = ft_atoi(rgb_values[0]);
		cl->g = ft_atoi(rgb_values[1]);
		cl->b = ft_atoi(rgb_values[2]);
		cl->rgb = create_rgb(cl->r, cl->g, cl->b);
		(*count)++;
		return (0);
	}
	else
		return (print(ERR_DUP_RGB));
}

static int	check_rgb_values(char **rgb_values)
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
			else if (ft_strlen(rgb_values[i]) >= 4)
				return (print(ERR_RGB_INT_OVERFLOW));
			j++;
		}
		if (ft_atoi(rgb_values[i]) < 0 || ft_atoi(rgb_values[i]) > 255)
			return (print(ERR_RGB_OUT_OF_RANGE));
		i++;
	}
	return (0);
}

int	set_rgb_values(t_pars *pars, char **lines, int *out, int *count)
{
	char	**rgb_values;

	if (validate_rgb_commas(lines[1]))
		return (1);
	rgb_values = ft_split(lines[1], ',');
	if (!rgb_values)
		return (1);
	if (rgb_values[3])
	{
		__free((void ***)&rgb_values);
		print(ERR_RGB_OVERFLOW);
		return (1);
	}
	if (check_rgb_values(rgb_values))
		return (__free((void ***)&rgb_values));
	if (set_fl_or_cl(pars, rgb_values, out, count))
		return (__free((void ***)&rgb_values));
	__free((void ***)&rgb_values);
	return (0);
}
