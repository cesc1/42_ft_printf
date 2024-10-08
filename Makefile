#
NAME = libftprintf.a
LIBS = libft/libft.a

HEAD = libftprintf.h \
       libftprintf_utils.h

SRCS = ft_printf.c \
       ft_cs_print.c \
       ft_cs_print_d.c \
       ft_cs_print_s.c \
       ft_cs_print_x.c \
       ft_cs_print_utils.c \
       ft_cs.c \
       ft_utils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

###############################

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile $(LIBS)
	ar rcs $(NAME) $(OBJS)

$(LIBS): 
	cd libft && make bonus

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
