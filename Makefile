#Compiler Options
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

#Libraries
LIBS = -lm -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft

MLX_DIR = /usr/local/lib
MLX_INCLUDE = /usr/local/include

#Mandatory
NAME = fractol
INCLUDES = -I $(SRCSDIR) -I $(LIBFT_DIR) -I $(MLX_INCLUDE)
SRCSDIR = srcs/
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

#Bonus
NAME_BONUS = fractol_bonus
INCLUDES_BONUS = -I $(SRCSDIR_BONUS) -I $(LIBFT_DIR) -I $(MLX_INCLUDE)
SRCSDIR_BONUS = srcs_bonus/
SRCS_BONUS =	main_bonus.c\
				colors_bonus.c\
				mandelbrot_bonus.c\
				julia_bonus.c\
				hooks_bonus.c\
				fractals_bonus.c\
				fern_bonus.c\
				set_atod_bonus.c\
				utils_bonus.c
OBJSDIR_BONUS = objs_bonus/
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJSDIR_BONUS)%.o)

#Debug
NAME_DEBUG = dbg
SRCSDIR_TO_DEBUG = $(SRCSDIR)
CFLAGS_DEBUG = -g -fsanitize=address -fsanitize=undefined
OBJSDIR_DEBUG = objs_debug/
OBJS_DEBUG = $($(SRCSDIR_TO_DEBUG):%.c=$(OBJSDIR_DEBUG)%.o)

vpath %.c $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.h $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.o $(OBJSDIR) $(OBJSDIR_BONUS) $(OBJSDIR_DEBUG)
vpath %.a $(LIBFT_DIR) $(MLX_DIR)

all: $(NAME)

#Mandatory
$(NAME) : libft $(OBJS)
	@printf "$(GREEN)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@printf "$(RESET)"
libft:
	@printf "$(GREEN_DIM)"
	make -C $(LIBFT_DIR)
	@printf "$(RESET)"
$(OBJSDIR)%.o: %.c
	@printf "$(GREEN_DIM)"
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(RESET)"

#Bonus
bonus: $(NAME_BONUS)
$(NAME_BONUS) : libft $(OBJS_BONUS)
	@printf "$(ORANGE)"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $@
	@printf "$(RESET)"
$(OBJSDIR_BONUS)%.o: %.c
	@printf "$(GREEN_DIM)"
	@mkdir -p $(OBJSDIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(RESET)"

#Debug
debug: $(NAME_DEBUG)
$(NAME_DEBUG) : libft $(OBJS_DEBUG)
	@printf "$(ORANGE)"
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(OBJS_DEBUG) $(LIBS) -o $@
	@printf "$(RESET)"
$(OBJSDIR_DEBUG)%.o: %.c
	@printf "$(GREEN_DIM)"
	@mkdir -p $(OBJSDIR_DEBUG)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(INCLUDES) -c $< -o $@
	@printf "$(RESET)"

#Others
run: all
	@printf "$(BLUE)"
	./$(NAME)
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

.PHONY: fclean all re clean libft debug
