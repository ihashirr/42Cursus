/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:44:35 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/27 22:51:15 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				len;
	unsigned char	b;

	i = 0;
	b = (unsigned char) c;
	if (!(str))
		return (NULL);
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == b)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;

	if (s1 == NULL)
	{
		s1 = (char *)malloc (sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstring = (char *)malloc(ft_strlen(s1)+ft_strlen(s2)+ 1);
	if (newstring == NULL)
		return (NULL);
	ft_strcpy(newstring, (char *)s1);
	ft_strcat(newstring, (char *)s2);
	free(s1);
	return (newstring);
}
