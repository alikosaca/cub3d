/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:26:53 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/17 14:15:35 by yaycicek         ###   ########.fr       */
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
	int		count;
	t_tex	tex;
	t_rgb	fl;
	t_rgb	cl;
	t_map	map;
}	t_pars;

int		parser(t_pars *pars, char *file);

int		get_file_height(int *height, char *file, int fd);
int		fill_grid(char **grid[], char *file, int fd);
int		check_invalid_whitespace(char *grid[]);

char	**get_split_lines(char *line);

int		init_tex(t_pars *pars, char *grid[], int *i);
int		is_xpm_file(t_tex *tex, int *out);

int		init_rgb(t_pars *pars, char *grid[], int *i);
void	init_rgb_values(t_rgb *fl, t_rgb *cl, bool *initialized);
int		set_rgb_values(t_pars *pars, char **lines, int *out);

int		init_map(t_pars *pars, t_map *map, char *grid[], int *i);
int		set_map_height(int *height, char *grid[], int *i);
void	set_map_max_width(int *max_width, char *grid[], int *i);
void	*alloc_map_rows(char **map[], int max_width, int height);
int		fill_map(t_map *map, char *grid[], int *i);

void	destroy_pars(t_pars *pars);

# define PARSER_H
#endif
