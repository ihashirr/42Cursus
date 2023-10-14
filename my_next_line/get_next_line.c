#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "string.h"

#define BUFFER_SIZE 5

char *get_next_line(int fd){

	char *buf;
	buf =(char *) malloc(sizeof(char) (BUFFER_SIZE + 1));
	if((fd<0 || BUFFER_SIZE <=0)|| !buf)
		return NULL;
	
}
int main()
{

	int fd;
	char *line;

	fd = open("shortLines.txt", O_RDONLY);
	line = get_next_line(fd)
	printf("%s\n", line);
	printf("%s\n", "EOF");
	close(fd)
	free(line);
}

