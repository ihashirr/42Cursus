/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:58:17 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 06:10:32 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	check;

	check = 1;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 1 || nb == 0)
	{
		return (1);
	}
	else
	{
		while (nb > 1)
		{
			check = check * nb;
			nb--;
		}
	}
	return (check);
}
