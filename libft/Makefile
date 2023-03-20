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

#Compiler Preferences
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_DEBUG = -g -fsanitize=address -fsanitize=undefined
CFLAGS_LEAK = -g -fsanitize=leak


NAME = libft.a
SRCS =\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	\
	ft_calloc.c\
	ft_strdup.c\
	\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	\
	\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	\
	ft_lstiter.c\
	ft_lstmap.c\
	\
	\
	ft_printf/ft_printf.c\
	ft_printf/ft_putchrs.c\
	ft_printf/ft_putnums.c\
	\
	get_next_line/get_next_line_bonus.c\
	get_next_line/get_next_line_utils_bonus.c\
	\
	ft_chrmatch.c\
	ft_malloc.c\
	ft_exit.c\
	ft_isspace.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: fclean all re clean
