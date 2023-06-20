# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 22:20:39 by dmogi             #+#    #+#              #
#    Updated: 2023/03/13 15:16:31 by dmogi            ###   ########.jp        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o \
		ft_strnstr.o ft_strncmp.o ft_memset.o ft_bzero.o ft_memcpy.o \
		ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_atoi.o \
		ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
		ft_toupper.o ft_tolower.o ft_calloc.o ft_strdup.o ft_substr.o \
		ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o
B_OBJS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
		 ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
	 	 ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS) $(B_OBJS)
	ar rc $(NAME) $(OBJS) $(B_OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $^
	
clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
