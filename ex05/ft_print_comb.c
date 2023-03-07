/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 06:20:25 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/07 05:04:29 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(int num1, int num2, int num3)
{
	write(1, &num1, 1);
	write(1, &num2, 1);
	write(1, &num3, 1);
	if (num1 != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	loop_var1;
	int	loop_var2;
	int	loop_var3;

	loop_var1 = '0';
	loop_var2 = '1';
	loop_var3 = '2';
	while (loop_var1 <= '7')
	{
		loop_var2 = loop_var1 + 1;
		while (loop_var2 <= '8')
		{
			loop_var3 = loop_var2 + 1;
			while (loop_var3 <= '9')
			{
				ft_printing(loop_var1, loop_var2, loop_var3);
				loop_var3++;
			}
			loop_var2++;
		}
		loop_var1++;
	}
}
