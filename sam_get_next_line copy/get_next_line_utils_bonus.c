/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizerese <sizerese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:13:08 by sizerese          #+#    #+#             */
/*   Updated: 2023/09/29 21:26:44 by sizerese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *my_stash, char *buffer)
{
	int		i;
	int		j;
	char	*result;

	if (!my_stash)
		my_stash = ft_calloc(1, sizeof(char));
	if (!my_stash || !buffer)
		return (ft_free_st(&my_stash));
	j = 0;
	i = 0;
	result = ft_calloc(ft_strlen(my_stash) + 
			ft_strlen(buffer) + 1, sizeof(char));
	if (!result)
		return (ft_free_st(&my_stash));
	while (my_stash[i])
		result[j++] = my_stash[i++];
	i = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';
	free(my_stash);
	return (result);
}
