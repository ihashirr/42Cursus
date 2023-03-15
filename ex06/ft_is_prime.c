/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:00:28 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 06:08:47 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	checker;

	if (nb < 2)
		return (0);
	if (nb > 2 && (nb % 2 == 0))
		return (0);
	if (nb > 5 && (nb % 5 == 0))
		return (0);
	checker = 3;
	while (checker <= (nb / checker))
	{
		if (nb % checker == 0)
			return (0);
		checker += 2;
	}
	return (1);
}
