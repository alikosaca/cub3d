/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:43:24 by yaycicek          #+#    #+#             */
/*   Updated: 2025/10/17 17:03:17 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_INVALID_ARGS "Usage: ./cub3D <map.cub>"
# define ERR_INVALID_EXTENSION "Map file must have a .cub extension"
# define ERR_FILE_MISS_OR_UNREAD "Map file does not exist or is not readable"
# define ERR_EMPTY_MAP "Map file cannot be empty"
# define ERR_INVALID_WHITESPACE  "Map file contains invalid whitespace char(s)"
# define ERR_INVALID_LINE "Map file has invalid line(s)"
# define ERR_MISS_PATH "Map file has missing texture path"
# define ERR_MULTI_PATH "Map file has multiple paths for a texture"
# define ERR_DUP_TEX "Map file has duplicate texture definition"
# define ERR_TEX_FILE "Map file has missing or unreadable texture file"
# define ERR_INVALID_TEX_EXT "Texture file must have a .xpm extension"
# define ERR_MISS_RGB "Map file has missing RGB color definition"
# define ERR_MULTI_RGB "Map file has multiple RGB color definitions"
# define ERR_RGB_OVERFLOW "RGB color cannot have more than 3 values"
# define ERR_TRAIL_COMMA_RGB "RGB color definition cannot end with a ','"
# define ERR_RGB_NOT_NUM "RGB value(s) must be a positive integer without sign"
# define ERR_RGB_OUT_OF_RANGE "RGB color value(s) must be between 0 and 255"
# define ERR_DUP_RGB "Map file has duplicate RGB color definition"
# define ERR_PREMATURE_MAP "Map section cannot start before all values are set"
# define ERR_MISS_MAP "Map file has missing map section"
# define ERR_MAP_TOO_SMALL "Map section must have at least 3 rows"
# define ERR_NO_PLAYER "Map section has no player"
# define ERR_MULTI_PLAYER "Map section has multiple player"
# define ERR_TRAIL_NL "Map section contains extra newline(s) at the end"
# define ERR_DUP_MAP_ROWS "Map section must not have two consecutive map rows"
# define ERR_INVALID_MAP_CHAR "Map section contains invalid character(s)"
# define ERR_OPEN_MAP "Map section is not closed by walls"
# define ERR_MULTI_MAP "Map section cannot contain more than one map"

# define ERR_CREATE_MLX "Could not create mlx"
# define ERR_CREATE_XPM "Could not create xpm file"
# define ERR_CREATE_IMG "Could not create image"
# define ERR_OPEN_WIN "Could not create window"
# define ERR_INIT_ADDR "Could not init mlx_get_data_addr"

#endif
