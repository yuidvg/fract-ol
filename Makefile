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
vpath %.c $(SRCSDIR) $(SRCSDIR)bonus/
vpath %.h $(SRCSDIR)
vpath %.o $(OBJSDIR)

#libft
LIBFT = libft/libft.a

#Mandatory
NAME = push_swap
SRCS =          assign_nums.c\
				compress.c\
				errors.c\
				m_sort.c\
				pull_target.c\
				push_swap.c\
				push.c\
				reverse_rotate.c\
				rotate.c\
				solve.c\
				swap.c
OBJS = $(SRCS:%.c=$(OBJSDIR)%.o)
INCLUDES = -I $(SRCSDIR)

#Bonus
NAME_BONUS = checker
SRCS_BONUS =    assign_nums_bonus.c\
				errors_bonus.c\
				push_bonus.c\
				checker_bonus.c\
				reverse_rotate_bonus.c\
				rotate_bonus.c\
				swap_bonus.c\
				manipulate_bonus.c
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJSDIR)%.o)
INCLUDES_BONUS = -I $(SRCSDIR)bonus/

all: $(OBJSDIR) $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@printf "$(GREEN)"
	$(CC) $(CFLAGS) $(INCLUDES) $+ -o $@
	@printf "$(RESET)"

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@printf "$(GREEN)"
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) $+ -o $@
	@printf "$(RESET)"

$(LIBFT):
	@printf "$(GREEN_DIM)"
	make -C ./libft
	@printf "$(RESET)"

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

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
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_BONUS) -c $^ -o $@
	@printf "$(RESET)"

.PHONY: fclean all re clean bonus
