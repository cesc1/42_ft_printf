# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faguirre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 11:03:57 by faguirre          #+#    #+#              #
#    Updated: 2024/10/09 13:51:32 by faguirre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRCS_BONUS = $(patsubst %.c, %_bonus.c, $(SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

###############################

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile $(LIBS)
	ar rcs $(NAME) $(OBJS)

$(LIBS): 
	cd libft && make

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

make bonus: $(OBJS_BONUS) $(LIBS)
	ar rcs $(NAME) $(OBJS_BONUS)
	sleep 0.01
	touch $(HEAD)

.PHONY: all clean fclean re bonus
