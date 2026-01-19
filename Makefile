NAME      = cub3D

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS   = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS    = -lft -lmlx -lXext -lX11 -lm

RM        = rm -rf

INC_DIR   = include
LIB_DIR   = lib
LIBFT_DIR = $(LIB_DIR)/libft
MLX_DIR   = $(LIB_DIR)/minilibx-linux
SRC_DIR   = src
PRS_DIR   = parser
EXC_DIR   = executor
RAY_DIR   = raycasting
UTL_DIR   = utils
BUILD_DIR = build
BIN_DIR   = bin

LIBFT     = $(LIBFT_DIR)/libft.a
MLX       = $(MLX_DIR)/libmlx.a
TARGET    = $(BIN_DIR)/$(NAME)

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
            $(SRC_DIR)/$(PRS_DIR)/map_validate.c \
            $(SRC_DIR)/$(PRS_DIR)/map_validate_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/flood_fill.c \
            $(SRC_DIR)/$(PRS_DIR)/flood_fill_utils.c \
            $(SRC_DIR)/$(PRS_DIR)/destroy.c
EXC       = $(SRC_DIR)/$(EXC_DIR)/executor.c \
            $(SRC_DIR)/$(EXC_DIR)/map_init.c \
            $(SRC_DIR)/$(EXC_DIR)/hooks.c \
            $(SRC_DIR)/$(EXC_DIR)/hooks_utils.c \
			$(SRC_DIR)/$(EXC_DIR)/tex_init.c \
            $(SRC_DIR)/$(EXC_DIR)/destroy.c
RAY       = $(SRC_DIR)/$(EXC_DIR)/$(RAY_DIR)/raycasting.c \
            $(SRC_DIR)/$(EXC_DIR)/$(RAY_DIR)/raycasting_utils.c
UTL       = $(SRC_DIR)/$(UTL_DIR)/print.c \
            $(SRC_DIR)/$(UTL_DIR)/alloc.c \
            $(SRC_DIR)/$(UTL_DIR)/free.c

ALL       = $(SRC) $(PRS) $(EXC) $(RAY) $(UTL)
OBJ       = $(ALL:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(LIBFT) $(MLX) $(TARGET)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(TARGET): $(OBJ) $(MLX)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(BUILD_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(BIN_DIR)

re: fclean all

norm:
	@norminette lib/libft src include

term: all
	@valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	./$(TARGET) $(ARG)

.PHONY: all clean fclean re norm term
