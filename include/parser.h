/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:26:53 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/01 13:43:04 by yaycicek         ###   ########.fr       */
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

int		parser(t_pars *pars, char *file);

int		get_file_height(int *height, char *file, int fd);
int		fill_grid(char *grid[], char *file, int fd);
int		check_invalid_whitespace(char *grid[]);

int		is_identifier(char *line);
int		is_mapline(char *line);
char	**get_split_lines(char *line);

int		init_tex(t_pars *pars, char *grid[], int i, int *count);
int		is_xpm_file(t_tex *tex, int *out);

int		init_rgb(t_pars *pars, char *grid[], int i, int *c);
void	init_rgb_values(t_rgb *fl, t_rgb *cl, bool *initialized);
int		set_rgb_values(t_pars *pars, char **lines, int *out, int *c);

int		init_map(t_pars *pars, char *grid[], int i);
int		set_map_height(int *h, char *grid[], int i);
void	set_map_max_width(int *max_w, char *grid[], int i);
int		alloc_map(char **map[], int h, int max_w);
int		fill_map(t_map *map, char *grid[], int i);

int		validate_map(t_map *map);
int		alloc_copy(char **copy[], char *map[], int h, int max_w);

void	destroy_pars(t_pars *pars);

# define PARSER_H
#endif
