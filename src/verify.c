/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:42:29 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/17 15:31:05 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_file_readable(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

static int	check_file_extension(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strcmp(ext, ".cub") != 0 || ft_strlen(file) == 4)
		return (1);
	return (0);
}

void	verify(int argc, char *file)
{
	if (argc != 2)
		exit(print(ERR_INVALID_ARGS));
	if (check_file_extension(file))
		exit(print(ERR_INVALID_EXTENSION));
	if (is_file_readable(file))
		exit(print(ERR_FILE_MISS_OR_UNREAD));
}
