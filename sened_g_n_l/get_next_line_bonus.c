/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:59:56 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/28 01:08:37 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_current_line(int fd, char *current_line)
{
	char	*buffer;
	ssize_t	num_bytes;

	num_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(current_line, '\n') == NULL && num_bytes > 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (current_line == NULL && num_bytes == 0)
			return (free(buffer), free(current_line), NULL);
		if (num_bytes == -1)
			return (free(buffer), free(current_line), NULL);
		buffer[num_bytes] = '\0';
		current_line = ft_strjoin (current_line, buffer);
	}
	free (buffer);
	return (current_line);
}

char	*ft_allocate_memory(char c, int i)
{
	char	*str;

	if (c != '\n')
	{
		str = (char *)malloc (sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (i + 2));
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = ft_allocate_memory(line[i], i);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *static_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (static_line[i] && static_line[i] != '\n')
		i++;
	if (!(static_line[i]) || ((static_line[i] == '\n') && !static_line[i + 1]))
	{
		free(static_line);
		static_line = NULL;
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(static_line) - i + 1);
	if (str == NULL)
		return (NULL);
	i++;
	while (static_line[i])
		str[j++] = static_line[i++];
	str[j] = '\0';
	free(static_line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*static_line[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	static_line[fd] = get_current_line(fd, static_line[fd]);
	if (static_line[fd] == NULL)
		return (NULL);
	next_line = ft_get_line(static_line[fd]);
	static_line[fd] = new_line(static_line[fd]);
	return (next_line);
}
int main (void)
{
	int fd;
	int fd1;
	char *line1;
	int i = 1;
	fd = open("file1.txt", O_RDONLY);
	fd1 = open("file2.txt", O_RDONLY);
	line1 = get_next_line(fd);
	printf("line %d: %s\n", i, line1);
	line1 = get_next_line(fd1);
	printf("line %d: %s\n", i, line1);
	line1 = get_next_line(fd);
	printf("line %d: %s\n", i, line1);
	line1 = get_next_line(fd1);
	printf("line %d: %s\n", i, line1);
}
