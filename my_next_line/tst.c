#include <stdio.h>
#include <stdlib.h>

void increment(char *str) {
    str= "s\0";
}

int main() {
	char*s;
	increment(s);

	printf("%s\n", s);
    return 0;
}