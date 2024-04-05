// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>
// #include <stdlib.h>

// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// int main(){
// 	int server_pid;
// 	printf("Enter the server pid: ");
// 	scanf("%d", &server_pid);

// 	kill(server_pid, SIGUSR1);
// 	kill(server_pid, SIGUSR2);
// 	sleep(1);
// 	kill(server_pid,SIGKILL);

// 	return 0;
// }
// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// char str[80] = {0};
// int bit_index = 0;

// void handler(int sig){
// 	if (sig == SIGUSR1){
// 		str[bit_index / 8] |= (1 << (bit_index % 8));
// 	}
// 	bit_index++;
// 	kill(getppid(), SIGUSR1);
// }

// int main(){
// 	pid_t server_pid;

// 	printf("Enter the server pid: ");
// 	scanf("%d", &server_pid);

// 	signal(SIGUSR1,handler);
// 	signal(SIGUSR2,handler);

// 	kill(server_pid, SIGUSR1);
// 	sleep(1);

// 	printf("Received: %s\n", str);

// 	return 0;

// #include <signal.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// void send_bit(pid_t pid, char bit)
// {
// 	int ret;
// 	if (bit == '0')
// 	{
// 		ret = kill(pid, SIGUSR1);
// 	}
// 	else
// 	{
// 		ret = kill(pid, SIGUSR2);
// 	}
// 	if (ret == -1)
// 	{
// 		perror("kill");
// 		exit(EXIT_FAILURE);
// 	}
// 	usleep(100);
// }

// void send_string(pid_t pid, char *str)
// {
// 	while (*str)
// 	{
// 		for (int i = 7; i >= 0; i--)
// 		{
// 			send_bit(pid, (*str >> i) & 1 ? '1' : '0');
// 		}
// 		str++;
// 	}
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		printf("Usage: %s <server_pid> <string>\n", argv[0]);
// 		exit(1);
// 	}

// 	pid_t server_pid = atoi(argv[1]);
// 	if (server_pid <= 0)
// 	{
// 		printf("Invalid server PID.\n");
// 		exit(1);
// 	}

// 	send_string(server_pid, argv[2]);
// 	return 0;
// }

#include "minitalk.h"

int main(int argc, char **argv)
{
	int i;
	int shift;
	pid_t pid;
	int c = 0;
	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
		{
			shift = 8;
			while (shift-- > 0)
			{
				if ((argv[2][i] >> shift) & 1)
					{

						kill(pid, SIGUSR1);
						printf("The %dth bit is: 1\n",c);
						c++;
					}
				else{
					kill(pid, SIGUSR2);
					printf("The %dth bit is: 0\n", c);
					c++;
				}
				usleep(30);
			}
		}
	}
	else
		write(1, "~~Usage pid and message~~\n", 20);
}