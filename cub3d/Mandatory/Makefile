# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmogi <mogi.t218140@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:28:08 by dmogi             #+#    #+#              #
#    Updated: 2023/03/14 13:16:05 by dmogi            ###   ########.jp        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra

HEADER=cub3d.h
CUB_OBJS= main.o calc_wall.o check_map.o draw.o error_check.o hook_funcs.o init_params.o load_texture.o my_free_libs.o my_library.o set_map_data.o set_map_data_utils.o
GNL_OBJS= get_next_line.o get_next_line_utils.o
NAME=cub3d

MAP_HEADER=../CREATE_MAP/maze.h
MAP_OBJ=../CREATE_MAP/create_map.o
MAP_FILE=map.cub

all: $(NAME) map

$(NAME): $(CUB_OBJS) $(GNL_OBJS)
	$(CC) -o $@ $^ -Lmlx -lmlx -framework OpenGL -framework AppKit

map: $(MAP_OBJ) $(MAP_HEADER)
	$(CC) -o $@ $<
	rm -f $<

clean:
	rm -f $(CUB_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f map $(NAME) $(MAP_FILE)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<
