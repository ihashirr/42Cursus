/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:23:11 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/14 03:14:12 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	counter;
	int	src_size;

	counter = 0;
	src_size = 0;
	while (dest[src_size] != '\0')
	{
		src_size++ ;
	}
	while (src[counter] != '\0')
	{
		dest[src_size] = src[counter];
		counter++ ;
		src_size++ ;
	}
	dest[src_size] = '\0';
	return (dest);
}
