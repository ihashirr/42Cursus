/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizerese <sizerese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:07:07 by sizerese          #+#    #+#             */
/*   Updated: 2023/09/29 21:26:47 by sizerese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int b)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (b == str[i])
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\0' && b == '\0')
		return ((char *)str + i);
	return (0);
}

static void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)str;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && count > UINT_MAX / size)
		return (NULL);
	i = size * count;
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}

char	*ft_strjoin(char *stash_strings, char *buff)
{
	int		i;
	int		c;
	char	*result;

	if (!stash_strings)
		stash_strings = ft_calloc(1, sizeof(char));
	if (!stash_strings || !buff)
		return (ft_free_st(&stash_strings));
	result = (char *) malloc(sizeof(char) * 
			(ft_strlen(stash_strings) + ft_strlen(buff) + 1));
	if (!result)
		return (ft_free_st(&stash_strings));
	i = 0;
	c = 0;
	while (stash_strings[i])
		result[c++] = stash_strings[i++];
	i = 0;
	while (buff[i])
		result[c++] = buff[i++];
	result[c] = '\0';
	free(stash_strings);
	return (result);
}
