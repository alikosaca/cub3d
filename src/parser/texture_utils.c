/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:33 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/13 00:54:04 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_xpm_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strcmp(ext, ".xpm") != 0 || ft_strlen(file) == 4)
		return (print(ERR_INVALID_TEX_EXT));
	return (0);
}

static int	validate_xpm_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print(ERR_TEX_FILE));
	if (check_xpm_ext(file))
		return (close(fd), print(ERR_INVALID_TEX_EXT));
	close(fd);
	return (0);
}

int	is_xpm_file(t_pars *pars, int *out)
{
	char	*file;

	if ((*out) == 2)
		file = pars->tex.no;
	else if ((*out) == 3)
		file = pars->tex.so;
	else if ((*out) == 4)
		file = pars->tex.we;
	else if ((*out) == 5)
		file = pars->tex.ea;
	else
		return (0);
	return (validate_xpm_file(file));
}
