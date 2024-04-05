#ifndef MINITALK_H
#define MINITALK_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
// #include "libft/libft.h"
#include "../ft_printf/ft_printf.h"

// int	    ft_atoi(char *str);
// void	ft_putnbr(int nb);
void	ft_putchar(char c);
int ft_atoi(const char *s);
// void	ft_putstr(char *s);
typedef struct init{
    int i;
    char c;
}init;

#endif 