NAME      = cub3D

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS   = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS    = -lmlx -lXext -lX11 -lm

RM        = rm -f

INC_DIR   = include
LIBFT_DIR = libft
MLX_DIR   = minilibx-linux
SRC_DIR   = src

LIBFT     = $(LIBFT_DIR)/libft.a
MLX       = $(MLX_DIR)/libmlx.a

SRC       = $(wildcard $(SRC_DIR)/*.c)
OBJ       = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
