.PHONY: all clean fclean re printf server client sclean server_bonus client_bonus bonus
CC=cc
CFLAGS= -Wall -Werror -Wextra 
LDFLAGS=  -Lft_printf -lftprintf

INC_BONUS=./$(bon)/minitalk.h
INC_MAN=./$(man)/minitalk.h

bon=bonus
man=mandatory

CFILES = ./$(man)/server.c ./$(man)/client.c ./$(man)/utils.c ./$(bon)/server_bonus.c ./$(bon)/client_bonus.c ./$(bon)/utils_bonus.c
OBJ= $(CFILES:.c=.o)

all: printf server client sclean

$(bon): server_bonus client_bonus

printf:
	make -C ft_printf

server: ./$(man)/server.o ./$(man)/utils.o ./$(INC_MAN)
	$(CC) $(CFLAGS) ./$(man)/server.o ./$(man)/utils.o $(LDFLAGS) -o server

client: ./$(man)/client.o ./$(man)/utils.o ./$(INC_MAN)
	$(CC) $(CFLAGS) ./$(man)/client.o ./$(man)/utils.o $(LDFLAGS) -o client
 
server_bonus: $(bon)/server_bonus.o $(bon)/utils_bonus.o $(INC_BONUS)
	$(CC) $(CFLAGS) $(bon)/server_bonus.o $(bon)/utils_bonus.o $(LDFLAGS) -o server_bonus

client_bonus: $(bon)/client_bonus.o $(bon)/utils_bonus.o $(INC_BONUS)
	$(CC) $(CFLAGS) $(bon)/client_bonus.o $(bon)/utils_bonus.o $(LDFLAGS) -o client_bonus

fclean: clean
	rm -f server client server_bonus client_bonus 
clean:
	rm -rf ./$(man)/*.o
	rm -rf ./$(bon)/*.o

re: fclean all

sclean:
	rm -rf ./$(man)/*.o
	rm -rf ./$(bon)/*.o
