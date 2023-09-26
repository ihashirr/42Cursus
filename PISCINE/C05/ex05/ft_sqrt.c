/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:00:15 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 06:08:17 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_sqrt(int nb, int i)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (i);
	return (ft_find_sqrt(nb - ((i * 2) + 1), i + 1));
}

int	ft_sqrt(int nb)
{
	return (ft_find_sqrt(nb, 0));
}
