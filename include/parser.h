/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:26:53 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/08 19:31:13 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# include <stdbool.h>
# include <fcntl.h>

# include "libft.h"
# include "utils.h"

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_colors
{
	int		floor[3];
	int		ceiling[3];
}	t_colors;

typedef struct s_map
{
	char	**map;
	int		max_width;
	int		height;
	int		p_x;
	int		p_y;
	char	p_dir;
}	t_map;

typedef struct s_parser
{
	t_textures	textures;
	t_colors	colors;
	t_map		map;
}	t_parser;

int	parser(t_parser *parser, char *file);

int	get_file_height(char *file, int *fd, int *height);
int	fill_grid(char *file, int *fd, char ***grid);

# define PARSER_H
#endif
