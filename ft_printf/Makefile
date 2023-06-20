# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 22:22:21 by dmogi             #+#    #+#              #
#    Updated: 2022/12/22 09:28:37 by dmogi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_printf.o ft_printf_utils.o output_funcs.o \
	   output_funcs2.o check_frmt_funcs.o
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@
