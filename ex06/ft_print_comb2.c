/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 06:30:52 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/05 07:08:58 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char printer)
{
	write(1, &printer, 1);
}

void	ft_combination(int a, int b, bool boolean)
{
	ft_putchar(48 + a / 10);
	ft_putchar(48 + a % 10);
	ft_putchar(' ');
	ft_putchar(48 + b / 10);
	ft_putchar(48 + b % 10);
	if (boolean)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	boolean;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			boolean = !(a == 98 && b == 99);
			ft_combination(a, b, boolean);
			b++;
		}
		a++;
	}
}
