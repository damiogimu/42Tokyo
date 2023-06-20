CC=gcc
CFLAGS=-Wall -Werror -Wextra

OBJS=bitmap.o calc_sprite.o calc_wall.o check_map.o draw.o error_check.o\
	 get_next_line_utils.o get_next_line.o hook_funcs.o init_params.o load_texture.o\
	 my_free_libs.o my_library.o set_map_data.o set_map_data_utils.o main.o
HEADER=cub3d.h
NAME=cub3d

MAP_HEADER=../CREATE_MAP/maze.h
MAP_OBJ=../CREATE_MAP/create_map_for_old.o
MAP_FILE=field.cub

all:$(NAME) map

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^ libmlx.dylib -framework OpenGL -framework AppKit

map: $(MAP_OBJ) $(MAP_HEADER)
	$(CC) -o $@ $<
	rm -f $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f map $(NAME) $(MAP_FILE)

re: fclean all

%.o:%.c $(HEADER)
	$(CC) $(CFALGS) -c -o $@ $<

.PHONY: all clean fclean re
