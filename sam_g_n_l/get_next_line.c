/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:37:22 by sizerese          #+#    #+#             */
/*   Updated: 2023/09/30 01:14:55 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_st(char **stash_strings)
{
	free(*stash_strings);
	*stash_strings = NULL;
	return (NULL);
}

char	*ft_get_all_lines(int fd, char *stash_strings)
{
	int		fd_bytes;
	char	*buff;

	if (!stash_strings)
		stash_strings = ft_calloc(1, sizeof(char));
	buff = ft_calloc((size_t)(BUFFER_SIZE) + 1, sizeof(char));
	if (!buff)
		return (ft_free_st(&stash_strings));
	fd_bytes = 1;
	while (!ft_strchr(stash_strings, '\n') && fd_bytes != 0)
	{
		fd_bytes = read(fd, buff, BUFFER_SIZE);
		if ((fd_bytes == -1) || !stash_strings)
		{
			return (free(buff), free(stash_strings), NULL);
		}
		buff[fd_bytes] = '\0';
		stash_strings = ft_strjoin(stash_strings, buff);
	}
	free(buff);
	return (stash_strings);
}

char	*ft_get_one_line(char *stash_srings)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash_srings[0])
		return (NULL);
	while (stash_srings[i] && stash_srings[i] != '\n')
		i++;
	if (stash_srings[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash_srings[j] && stash_srings[j] != '\n')
	{
		line[i++] = stash_srings[j++];
	}
	if (stash_srings[j] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_extract_next_stash(char *stash_strings)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	if (!stash_strings)
		return (NULL);
	while (stash_strings[i] && stash_strings[i] != '\n')
		i++;
	if (!stash_strings[i])
		return (free(stash_strings), NULL);
	next = ft_calloc((size_t)(ft_strlen(stash_strings) - i + 1), sizeof(char));
	if (!next)
		return (ft_free_st(&stash_strings));
	if (stash_strings[i] == '\n')
	{
		i++;
		j = 0;
		while (stash_strings[i])
			next[j++] = stash_strings[i++];
		next[j] = '\0';
	}
	free(stash_strings);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*stash_strings;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > UINT_MAX)
		return (0);
	stash_strings = ft_get_all_lines(fd, stash_strings);
	if (!stash_strings)
		return (NULL);
	line = ft_get_one_line(stash_strings);
	if (!line)
		return (ft_free_st(&stash_strings));
	stash_strings = ft_extract_next_stash(stash_strings);
	return (line);
}
int main(){
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);
	for (int i = 1; i < 7; i++)
	{
		line = get_next_line(fd1);
		printf("line[%i] %s", i, line);
		free(line);
	}
	close(fd);
}
