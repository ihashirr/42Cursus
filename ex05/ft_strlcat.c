/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:02:42 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/14 03:12:45 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	result;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	result = srclen;
	if (size <= destlen)
	{
		result = result + size;
	}
	else
	{
		result = result + destlen;
	}
	while (src[i] != '\0' && destlen + 1 < size)
	{
		dest[destlen] = src[i];
		destlen++ ;
		i++ ;
	}
	dest[destlen] = '\0';
	return (result);
}
