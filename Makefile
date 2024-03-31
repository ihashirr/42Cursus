.PHONY:  printf

CC=cc -g
CFLAGS=-Wall 
LDFLAGS=  -Lft_printf -lftprintf  

all: printf server client sclean

printf:
	make -C ft_printf

server: server.o utils.o minitalk.h
	$(CC) $(CFLAGS) server.o utils.o $(LDFLAGS) -o server

client: client.o utils.o minitalk.h
	$(CC) $(CFLAGS) client.o utils.o $(LDFLAGS) -o client

%.o: %.c
	$(CC) $(CFLAGS) -c $<

fclean: clean
	rm -f server client
 
clean:
	rm -rf *.o
 

re: fclean all

sclean:
	rm -rf *.o