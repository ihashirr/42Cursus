#include "minitalk.h"

// static int check_nbr(unsigned long nbr, int signe)
// {
// 	if (signe < 0)
// 	{
// 		if (nbr == 2147483648)
// 			return (-2147483648);
// 		return (0);
// 	}
// 	return (-1);
// }

// int ft_atoi(char *str)
// {
// 	unsigned long nombre;
// 	int signe;
// 	int i;

// 	i = 0;
// 	nombre = 0;
// 	signe = 1;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			signe = signe * -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nombre = nombre * 10;
// 		nombre = nombre + (int)(str[i] - '0');
// 		i++;
// 	}
// 	if (nombre >= 2147483648)
// 		return (check_nbr(nombre, signe));
// 	return (nombre * signe);
// }

// void ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 	}
// 	else if (nb < 0)
// 	{
// 		nb = -nb;
// 		ft_putchar('-');
// 		ft_putnbr(nb);
// 	}
// 	else if (nb <= 9)
// 	{
// 		ft_putchar(nb + '0');
// 	}
// 	else
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// }
int ft_atoi(const char *str)
{
	int sign;
	unsigned long long res;
	unsigned long long max;

	res = 0;
	sign = 1;
	max = 9223372036854775807;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > max && sign == 1)
			return (-1);
		if (res > max + 1 && sign == -1)
			return (0);
		str++;
	}
	return (res * sign);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}
// void ft_putstr(char *s)
// {
// 	int i;

// 	if (!s)
// 		return;
// 	i = 0;
// 	while (s[i])
// 	{
// 		ft_putchar(s[i]);
// 		i++;
// 	}
// }