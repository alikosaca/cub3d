/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaycicek <yaycicek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:43:24 by yaycicek          #+#    #+#             */
/*   Updated: 2025/09/11 21:36:35 by yaycicek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_INVALID_ARGS "Usage: .cub3D <map.cub>"
# define ERR_INVALID_EXTENSION "Map file must have a .cub extension"
# define ERR_FILE_MISS_OR_UNREAD "Map file does not exist or is not readable"
# define ERR_EMPTY_MAP "Map file cannot be empty"
# define ERR_INVALID_WHITESPACE  "Map file contains invalid whitespace char(s)"
# define ERR_MISS_PATH "Map file has missing texture path"
# define ERR_MULTI_PATH "Map file has multiple paths for a texture"
# define ERR_DUP_TEX "Map file has duplicate texture definition"
# define ERR_TEX_FILE "Map file has missing or unreadable texture file"
# define ERR_INVALID_TEX_EXT "Texture file must have a .xpm extension"
# define ERR_MISS_RGB "Map file has missing RGB color definition"
# define ERR_MULTI_RGB "Map file has multiple RGB color definitions"
# define ERR_RGB_OVERFLOW "RGB color cannot have more than 3 values"
# define ERR_TRAIL_COMMA_RGB "RGB color definition cannot end with a ','"

#endif
