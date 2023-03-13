/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:49:50 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/14 03:14:46 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	cunt;
	unsigned int	size_src;

	cunt = 0;
	size_src = 0;
	while (dest[size_src])
	{
		size_src++ ;
	}
	if (nb > cunt)
	{
		while (src[cunt] != '\0' && nb - 1 >= cunt)
		{
			dest[size_src] = src[cunt];
			cunt++ ;
			size_src++ ;
		}
	}
	dest[size_src] = '\0';
	return (dest);
}
