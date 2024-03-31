.PHONY: libft printf

CC=cc
CFLAGS=-Wall 
LDFLAGS=-Llibft -Lprintf -lftprintf -lft

all: libft printf server client sclean

libft:
	make -C libft

printf:
	make -C printf

server: server.o utils.o minitalk.h
	$(CC) $(CFLAGS) server.o utils.o $(LDFLAGS) -o server

client: client.o utils.o minitalk.h
	$(CC) $(CFLAGS) client.o utils.o $(LDFLAGS) -o client

%.o: %.c
	$(CC) $(CFLAGS) -c $<

fclean: clean
	rm -f server client
	make -C libft fclean
clean:
	rm -rf *.o
	make -C libft clean

re: fclean all

sclean:
	rm -rf *.o
	make -C libft clean