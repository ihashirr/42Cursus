#include <stdio.h>
#include <stdlib.h>

void Nuller(char *str){
	*(str+3)='\0';
}
int main(){
	char s[3] ="ha";
	// Nuller(s);
	printf("%s",s);

}