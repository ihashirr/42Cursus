/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:58:41 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 07:07:08 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*number;

	i = 0;
	range = max - min;
	if (min >= max)
	{
		return (NULL);
	}
	number = malloc(sizeof (int) * range);
	if (number == NULL)
	{
		return (NULL);
	}
	while (i < range)
	{
		number[i] = min;
		i++;
		min++;
	}
	return (number);
}
// int main (void)
// {
// 	int max = 8;
// 	int min = 2;
// 	int range = max - min;
// 	int *number= ft_range(min,max);
// 	int i=0;
// 	while (i < range)
// 	{
// 		printf("%d", number[i]);
// 		i++;
// 	}
// 	return (0);
// }