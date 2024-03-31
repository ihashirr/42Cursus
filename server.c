// #include <stdio.h>

// int get_least_significant_bit(int number) {
//   // Gets the least significant bit of a number using bitwise AND
//   return number & 1;  // 1 will only be returned if the LSB is 1
// }

// int main() {
//   int number1 = 10;  // Binary: 1010
//   int number2 = 15;  // Binary: 1111
//   printf("Least significant bit of %d: %d\n", number1, get_least_significant_bit(number1));
//   printf("Least significant bit of %d: %d\n", number2, get_least_significant_bit(number2));
//   return 0;
// }
#include <stdio.h>

// int get_least_significant_bit(int number)
// {
// 	// Gets the least significant bit of a number using bitwise AND
// 	return number & 1; // 1 will only be returned if the LSB is 1
// }

// int main()
// {
// 	int number1 = 99; // Binary: 1010
// 	int number2 = 68; // Binary: 1111
// 	printf("Least significant bit of %d: %d\n", number1, get_least_significant_bit(number1));
// 	printf("Least significant bit of %d: %d\n", number2, get_least_significant_bit(number2));
// 	return 0;
// }

// #define LIGHT_OFF 0 // Represent light being off (all bits 0)
// #define LIGHT_ON 1	// Represent light being on (all bits 1)

// int main()
// {

// 	int switch_state = LIGHT_OFF; // Initially the light is off

// 	// Turn on the light (set switch to 1)
// 	switch_state = switch_state | LIGHT_ON;

// 	if (switch_state == LIGHT_ON)
// 	{
// 		printf("The light is now on.\n");
// 	}
// 	else{
// 		printf("The light is now off.\n");

// 	}
// }

// #include <stdio.h>

// int main()
// {
// 	int num = 10;		  // Example number (binary: 1010)
// 	int bit_position = 2; // Position of the bit to set (0-indexed)

// 	// Mask with a 1 at the desired bit position
// 	int set_bit_mask =1<< bit_position;

// 	// Set the bit using OR
// 	num = num | set_bit_mask;

// 	printf("Number after setting bit %d: %d (binary: %d)\n", bit_position, num, num);

//       	return 0;
// }

#include <stdio.h>

// int main()
// {
// 	int num = 5;		  // Example number (binary: 101)
// 	int bit_position = 1; // Position of the bit to toggle (0-indexed)

// 	// Toggle bit mask with a 1 at the desired position
// 	int toggle_bit_mask = 1 << bit_position;

// 	// Toggle the bit using OR
// 	num = num ^ toggle_bit_mask; // XOR can also be used for toggling

// 	printf("Number after toggling bit %d: %d (binary: %d)\n", bit_position, num, num);

// 	return 0;
// }

// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// void handler(int sig){
// 	if (sig == SIGUSR1){
// 		printf("Recived 1\n");
// 	}
// 	else if (sig == SIGUSR2)
// 	{
// 		printf("Received SIGUSR2\n");
// 	}
// }
// int main(){
// 	printf("Srver pif: %d\n",getpid());

// 	signal(SIGUSR1,handler);
// 	signal(SIGUSR2,handler);

// 	while (1)
// 	{
// 		pause();
// 	}
	
// }


// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// char *str = "Hello from server";
// int bit_index = 0;

// void handler(int sig){
// 	if (sig == SIGUSR1){
// 		printf("Received SIGUSR1\n");
// 		kill(getppid(), (str[bit_index / 8] & (1 << (bit_index % 8))) ? SIGUSR1 : SIGUSR2);
// 		bit_index++;
// 	}
// }

// int main(){
// 	printf("Server pid: %d\n",getpid());

// 	signal(SIGUSR1,handler);

// 	while (1)
// 	{
// 		pause();
// 	}
	
// 	return 0;
// }

// #include <signal.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// char g_char = 0;
// int g_bits_received = 0;

// void handle_signal(int signal)
// {
// 	g_char |= (signal == SIGUSR2) << (7 - g_bits_received);
// 	g_bits_received++;
// 	if (g_bits_received == 8)
// 	{
// 		printf("%c\n", g_char);
// 		g_char = 0;
// 		g_bits_received = 0;
// 	}
// }

// int main()
// {
// 	struct sigaction sa;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = 0;
// 	sa.sa_handler = handle_signal;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	printf("Pid: %d\n",getpid());
// 	sigaction(SIGUSR2, &sa, NULL);
//  	while (1)
// 	{
// 		pause();
// 	}
// 	return 0;
// }
#include "minitalk.h"

init t;

void init_by_zero(void)
{
	t.c = (char)255;
	t.i = 0;
}

void handler1(int signum, siginfo_t *info, void *sheet)
{
	(void)sheet;
	int static pid;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		init_by_zero();
	}
	if (signum == SIGUSR1)
		t.c |= (0x80 >> t.i++);
	else if (signum == SIGUSR2)
		t.c ^= (0x80 >> t.i++);
	if (t.i == 8)
	{
		ft_putchar(t.c);
		init_by_zero();
	}
}

int main()
{
	int a = 0;
	struct sigaction new_act1;
	new_act1.sa_sigaction = &handler1;
	new_act1.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid(),"0123456789",10,&a);
		
	write(1, "\n", 1);

	sigaction(SIGUSR1, &new_act1, NULL);
	sigaction(SIGUSR2, &new_act1, NULL);
	while (1)
		pause();
}
 