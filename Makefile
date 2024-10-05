#
NAME = libftprintf.a

HEAD = printf.h
SRCS = ft_printf.c \
       ft_cs.c \
       ft_utils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile
	cd libft; make bonus
	ar rcs $(NAME) $(OBJS)

load_libft: 
	cd libft; make bonus

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re load_libft
