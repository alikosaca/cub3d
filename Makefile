NAME      = cub3D

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS   = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS    = -lft -lmlx -lXext -lX11 -lm

RM        = rm -f

INC_DIR   = include
LIB_DIR   = lib
LIBFT_DIR = $(LIB_DIR)/libft
MLX_DIR   = $(LIB_DIR)/minilibx-linux
SRC_DIR   = src
PRS_DIR   = parser
EXC_DIR   = executor
UTL_DIR   = utils

LIBFT     = $(LIBFT_DIR)/libft.a
MLX       = $(MLX_DIR)/libmlx.a

SRC       = $(SRC_DIR)/main.c \
            $(SRC_DIR)/verify.c \
            $(SRC_DIR)/cleanup.c
PRS       = $(SRC_DIR)/$(PRS_DIR)/parser.c \
            $(SRC_DIR)/$(PRS_DIR)/parser_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/grid_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/texture.c \
            $(SRC_DIR)/$(PRS_DIR)/texture_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/rgb.c \
            $(SRC_DIR)/$(PRS_DIR)/rgb_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/map.c \
            $(SRC_DIR)/$(PRS_DIR)/map_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/destroy.c
EXC       = $(SRC_DIR)/$(EXC_DIR)/executor.c \
            $(SRC_DIR)/$(EXC_DIR)/map_init.c \
            $(SRC_DIR)/$(EXC_DIR)/hooks.c \
            $(SRC_DIR)/$(EXC_DIR)/exit.c
UTL       = $(SRC_DIR)/$(UTL_DIR)/print.c \
            $(SRC_DIR)/$(UTL_DIR)/alloc.c \
            $(SRC_DIR)/$(UTL_DIR)/free.c

OBJ       = $(SRC:.c=.o) $(PRS:.c=.o) $(EXC:.c=.o) $(UTL:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette src include

term:
	@valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	./cub3D $(ARG)

.PHONY: all clean fclean re
