#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("shortLines.txt", O_RDONLY);
	char *str = calloc(100000, sizeof(char));	// initialize memory block to all zeros
	char *ptr = str;							// use separate pointer variable to iterate over memory block
	ssize_t bytes_read = read(fd, ptr, 100000); // read up to 100000 bytes from file descriptor
	int newline_count = 0; // initialize newline count to zero
	while (*ptr != '\0')
	{ // iterate over memory block until null terminator is found
		if (*ptr == '\n')
		{
			newline_count++; // increment newline count if newline character is found
		}
		ptr++;
	}
	printf("%s\n", str);							   // print string read from file
	printf("Number of newlines: %d\n", newline_count); // print number of newlines
	free(str);										   // free memory block
	close(fd);										   // close file descriptor
	return 0;
}