# Coder Alias
USER_NAME = jde-orma

# Compiler and flags
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror -I $(INC_DIR) -I $(MINILIBX_DIR) -I $(LIBFT_DIR)/include -O3

# Platform to run project (Linux and Mac)
PLATFORM  := $(shell uname)

# Directories
SRC_DIR   = source/
INC_DIR   = source/
LIBFT_DIR = libraries/libft/
OBJ_DIR   = source/

ifeq  ($(PLATFORM),Linux)
MINILIBX_DIR = libraries/minilib/linux/minilibx-linux/
LINKING = -lmlx_Linux -lXext -lX11 -lm
BIN_DIR   = bin/linux/
else
MINILIBX_DIR = libraries/minilib/IOS/minilibx_opengl_20191021/
LINKING = -lmlx -framework OpenGL -framework AppKit
BIN_DIR   = bin/IOS/
endif

# Source files
SRC_FILE = so_long_error_check.c so_long_keyboard_hook.c so_long_main.c so_long_map.c so_long_move.c so_long_pathfinder.c so_long_put_map.c so_long_put_xpm.c so_long_utils.c
SRC      = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ      = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Binary name for your program
CODE_BIN = $(BIN_DIR)so_long

# Static library
LIBFT    = $(LIBFT_DIR)libft.a
MINILIBX = $(MINILIBX_DIR)libmlx.a

# Output executable
NAME     = so_long.out

# Create the obj/ and bin/ directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Variable to control if the library has been built
LIBFT_BUILT    = no
MINILIBX_BUILT = no

all: $(CODE_BIN)

$(CODE_BIN): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L/usr/lib -L$(MINILIBX_DIR) $(LINKING) -o $@
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) compilation"

$(LIBFT):
	@if [ "$(LIBFT_BUILT)" = "no" ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
		LIBFT_BUILT=yes; \
	fi

$(MINILIBX):
	@if [ "$(MINILIBX_BUILT)" = "no" ]; then \
		$(MAKE) -C $(MINILIBX_DIR); \
		MINILIBX_BUILT=yes; \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) .o files removal"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(CODE_BIN)
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) executable and .o files removal"
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
