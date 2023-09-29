/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:44:35 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/28 00:56:38 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*static_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	static_line = get_current_line(fd, static_line);
	if (static_line == NULL)
		return (NULL);
	next_line = ft_get_line(static_line);
	static_line = new_line(static_line);
	return (next_line);
}
// int main(void)
// {
// 	int fd;
// 	char *line;
// 	int i;

// 	fd = open("file1.txt", O_RDONLY);
// 	i = 1;
// 	line = get_next_line(fd);
// 	printf("line %d: %s\n", i, line);
// 	line = get_next_line(fd);
// 	printf("line %d: %s\n", i, line);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 		// printf("World");
// 		// printf("line %d: %s\n", i, line);
// 		free(line);
// 		// i++;
// 	// }
// 	close(fd);
// 	return (0);
// }
