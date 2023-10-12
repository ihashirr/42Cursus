#include <stdio.h>
#include <stdlib.h>

void Nuller(char *str){
	*(str+3)='\0';
}
int main(){
	char a[];
	a = "has";
	printf("%d",*a);
	free(a);
	a = NULL;
}