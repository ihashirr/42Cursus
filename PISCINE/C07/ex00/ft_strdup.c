/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:47:16 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 14:34:24 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (dest);
}

// int main (int argc, char **argv)
// {
// 	char *str1;
// 	char *str2;
// 	if (argc == 2)
// 	{
// 		str1= ft_strdup(argv[1]);
// 		str2 = ft_strdup(argv[1]);
// 		printf("%s\n%s\n",str1, str2);

// 	}
// }
