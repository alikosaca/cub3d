#ifndef EXECUTOR_H

#define EXECUTOR_H

# include "cub3d.h"
# include "mlx.h"

typedef struct	s_map
{
	void	*mlx;
}				t_map;


int	executor(t_game *game);
int	init_mlx(t_map *map);

#endif