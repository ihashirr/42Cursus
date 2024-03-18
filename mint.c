#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig){
	printf("Caught Signal %d\n",sig);
}
int main(){
	signal(SIGINT, handle_sigint);
	while(1)
	{
		printf(" i Am a signal ");
		printf("The process ID is %d\n", getpid());
		printf("The u ID is %d\n", getuid());
		sleep(1);
	}
	return 0;
}