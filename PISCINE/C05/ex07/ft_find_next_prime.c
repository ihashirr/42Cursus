/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:07:49 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 06:09:16 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	checker;

	checker = 3;
	if (nb < 2)
	{
		return (0);
	}
	if (nb > 2 && (nb % 2 == 0))
	{
		return (0);
	}
	if (nb > 5 && (nb % 5 == 0))
	{
		return (0);
	}
	while (checker <= (nb / checker))
	{
		if (nb % checker == 0)
		{
			return (0);
		}
		checker += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while ((nb <= 2147483647) && (ft_is_prime(nb) == 0))
	{
		nb++;
	}
	return (nb);
}
