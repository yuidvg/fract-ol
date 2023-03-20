#Compiler Preferences
CC = cc
CFLAGS = -Wall -Werror -Wextra

#Colors
GRAY = \033[37;2m
GREEN = \033[32;1m
GREEN_DIM = \033[32;2m
BLUE = \033[34;1m
BLUE_DIM = \033[34;2m
RED = \033[31;1m
RED_DIM = \033[31;2m
YELLOW = \033[33;1m
YELLOW_DIM = \033[33;2m
ORANGE = \033[38;5;208m
ORANGE_DIM = \033[38;5;208;2m
RESET = \033[0m

#Common
SRCSDIR = srcs/
INCLUDES = -I $(SRCSDIR) -I $(LIBFT_DIR) -I $(MLX_INCLUDE)
LIBS = -lm -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#libft
LIBFT_DIR = libft

#MLX
MLX_DIR = /usr/local/lib
MLX_INCLUDE = /usr/local/include
#MLX_DIR = mlx
#MLX_INCLUDE = mlx

#Normal
NAME = fractol
SRCS =	main.c\
		colors.c\
		mandelbrot.c\
		julia.c\
		hooks.c\
		fractals.c\
		fern.c\
		set_atod.c\
		utils.c
OBJSDIR = objs/
OBJS = $(SRCS:%.c=$(OBJSDIR)%.o)


#Debug
NAME_DEBUG = dbg
CFLAGS_DEBUG = -g -fsanitize=address -fsanitize=undefined
OBJSDIR_DEBUG = objs_debug/
OBJS_DEBUG = $(SRCS:%.c=$(OBJSDIR_DEBUG)%.o)

vpath %.c $(SRCSDIR)
vpath %.h $(SRCSDIR)
vpath %.o $(OBJSDIR)
vpath %.a $(LIBFT_DIR)

all: $(NAME)

$(NAME) : libft $(OBJS)
	@printf "$(GREEN)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@printf "$(RESET)"

libft:
	@printf "$(GREEN_DIM)"
	make -C $(LIBFT_DIR)
	@printf "$(RESET)"

# mlx:
# 	@printf "$(GREEN_DIM)"
# 	make -C $(MLX_DIR)
# 	@printf "$(RESET)"

run: all
	@printf "$(BLUE)"
	./$(NAME)
	@printf "$(RESET)"

debug: fclean $(NAME_DEBUG)

$(NAME_DEBUG) : libft $(OBJS_DEBUG)
	@printf "$(ORANGE)"
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(OBJS_DEBUG) $(LIBS) -o $@
	@printf "$(RESET)"

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

$(OBJSDIR_DEBUG)%.o: %.c
	@printf "$(GREEN_DIM)"
	@mkdir -p $(OBJSDIR_DEBUG)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(RESET)"

.PHONY: fclean all re clean libft debug
