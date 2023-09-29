/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:11:53 by sizerese          #+#    #+#             */
/*   Updated: 2023/09/30 01:24:34 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_st(char **stash_strings)
{
	free(*stash_strings);
	*stash_strings = NULL;
	return (NULL);
}

char	*get_all_lines(int fd, char *my_stash)
{
	char	*buffer;
	int		fd_bytes;

	if (!my_stash)
		my_stash = ft_calloc(1, sizeof(char));
	fd_bytes = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (ft_free_st(&my_stash));
	while (!ft_strchr(my_stash, '\n') && fd_bytes != 0)
	{
		fd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (fd_bytes == -1 || my_stash == NULL)
			return (free(buffer), free(my_stash), NULL);
		buffer[fd_bytes] = '\0';
		my_stash = ft_strjoin(my_stash, buffer);
	}
	free(buffer);
	return (my_stash);
}

char	*get_one_line(char *my_stash)
{
	int		i;
	int		j;
	char	*line;

	if (!my_stash[0])
		return (NULL);
	i = 0;
	j = 0;
	while (my_stash[i] && my_stash[i] != '\n')
		i++;
	if (my_stash[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (my_stash[i] && my_stash[i] != '\n')
		line[j++] = my_stash[i++];
	if (my_stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*extract_last(char *my_stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (my_stash[i] && my_stash[i] != '\n')
		i++;
	if (!my_stash[i])
		return (free(my_stash), NULL);
	if (my_stash[i] == '\n')
		i++;
	new_stash = ft_calloc((size_t)(ft_strlen(my_stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (ft_free_st(&my_stash));
	while (my_stash[i])
		new_stash[j++] = my_stash[i++];
	new_stash[j] = '\0';
	free(my_stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*my_stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > UINT_MAX)
		return (NULL);
	my_stash[fd] = get_all_lines(fd, my_stash[fd]);
	if (!my_stash[fd])
		return (NULL);
	line = get_one_line(my_stash[fd]);
	if (!line)
		return (ft_free_st(&my_stash[fd]));
	my_stash[fd] = extract_last(my_stash[fd]);
	return (line);
}

int main(void)
{
	int fd1;
	int fd2;
	char *line1;
	char *line2;
	
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	for (int i = 1; i < 6; i++)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		printf("line[%d]: %s\n", i, line1);
		printf("line[%d]: %s\n", i, line2);
		free(line1);
		free(line2);
	}
	close(fd1);
	close(fd2);
}

