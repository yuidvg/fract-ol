#Compiler Preferences
CC = cc
CFLAGS = -Wall -Werror -Wextra

CFLAGS_DEBUG = -g -fsanitize=address -fsanitize=undefined
CFLAGS_LEAK = -g -fsanitize=leak

#Colors
GRAY = \033[37;2m
GREEN = \033[32;1m
GREEN_DIM = \033[32;2m
RED = \033[31;1m
RED_DIM = \033[31;2m
YELLOW = \033[33;1m
YELLOW_DIM = \033[33;2m
ORANGE = \033[38;5;208m
ORANGE_DIM = \033[38;5;208;2m
RESET = \033[0m

#Directories
SRCSDIR = srcs/
OBJSDIR = objs/

#libft
LIBFT_DIR = libft

#MLX
MLX_DIR = minilibx_mms_20191025_beta

NAME = fractol
SRCS =	main.c
OBJS = $(SRCS:%.c=$(OBJSDIR)%.o)
INCLUDES = -I $(SRCSDIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LIBS = -lm -L ./$(LIBFT_DIR) -lft -L ./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

vpath $(SRCS) $(SRCSDIR)
vpath %.h $(SRCSDIR)
vpath %.o $(OBJSDIR)

all: $(NAME)

$(NAME) : $(OBJS) libft mlx
	@printf "$(GREEN)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $^ -o $@
	@printf "$(RESET)"

libft:
	@printf "$(GREEN_DIM)"
	make -C $(LIBFT_DIR)
	@printf "$(RESET)"

mlx:
	@printf "$(GREEN_DIM)"
	make -C $(MLX_DIR)
	@printf "$(RESET)"

debug:
	$(CC) $(DEBUG)

clean:
	@printf "$(RED_DIM)"
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED_DIM)"
	make fclean -C ./libft
	@printf "$(RED)"
	rm -f $(NAME) $(NAME_BONUS)
	@printf "$(RESET)"

re: fclean all

$(OBJSDIR)%.o: %.c
	@printf "$(GREEN_DIM)"
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(RESET)"

.PHONY: fclean all re clean mlx libft
