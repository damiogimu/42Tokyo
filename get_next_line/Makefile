CC=gcc
CFLAGS=-Wall -Wextra
OBJS=test.o get_next_line.o get_next_line_utils.o

CHECK=check
LIB_GNL=lib
LIB_GNL_NAME=libgnl.a

$(CHECK):$(OBJS)
	$(CC) $(CFLAGS) -o $(CHECK) $^

$(LIB_GNL): $(OBJS)
	ar rc $(LIB_GNL_NAME) $^

clean:
	rm -f $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@ 
