/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:26:53 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/09 11:29:21 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# include <stdbool.h>
# include <fcntl.h>

# include "libft.h"
# include "utils.h"

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_tex;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_map
{
	char	**map;
	int		max_w;
	int		h;
	int		p_x;
	int		p_y;
	char	p_dir;
}	t_map;

typedef struct s_pars
{
	t_tex	tex;
	t_rgb	fl;
	t_rgb	cl;
	t_map	map;
}	t_pars;

int	parser(t_pars *pars, char *file);

int	get_file_height(char *file, int fd, int *height);
int	fill_grid(char *file, int fd, char ***grid);
int	check_invalid_whitespace(char **grid);

# define PARSER_H
#endif
