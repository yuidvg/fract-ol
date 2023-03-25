#Compiler Options
CC = cc
CFLAGS = -Wall -Werror -Wextra

#Libraries
LIBS = -lm -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

NAME_LIBFT = libft.a
LIBFT_DIR = libft/

MLX_DIR = /usr/local/lib/
MLX_INCLUDE = /usr/local/include/

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
CFLAGS_DEBUG = -g -fsanitize=address -fsanitize=undefined
NAME_DEBUG = dbg
INCLUDES_DEBUG = $(INCLUDES)
SRCS_DEBUG = $(SRCS)
OBJSDIR_DEBUG = objs_debug/
OBJS_DEBUG = $(SRCS_DEBUG:%.c=$(OBJSDIR_DEBUG)%.o)

vpath %.c $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.h $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.o $(OBJSDIR) $(OBJSDIR_BONUS) $(OBJSDIR_DEBUG)
vpath %.a $(LIBFT_DIR) $(MLX_DIR)

all: $(NAME)

#Libraries
$(NAME_LIBFT):
	make -C $(LIBFT_DIR)

#Mandatory
$(NAME): $(NAME_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
$(OBJSDIR)%.o: %.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Bonus
bonus: $(NAME_BONUS)
$(NAME_BONUS): $(NAME_LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $@
$(OBJSDIR_BONUS)%.o: %.c
	@mkdir -p $(OBJSDIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

#Debug
debug: $(NAME_DEBUG)
$(NAME_DEBUG): $(NAME_LIBFT) $(OBJS_DEBUG)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(OBJS_DEBUG) $(LIBS) -o $@
$(OBJSDIR_DEBUG)%.o: %.c
	@mkdir -p $(OBJSDIR_DEBUG)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(INCLUDES_DEBUG) -c $< -o $@

#Others
run: all
	./$(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJS_DEBUG)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS) $(NAME_DEBUG)

re: fclean all

.PHONY: fclean all re clean debug
