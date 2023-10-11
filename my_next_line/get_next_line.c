#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif
#include <time.h>
int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// char *ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t i;
// 	size_t j;
// 	char *str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (*src != '\0' && i < dstsize - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *result;
	size_t trimlen;

	if (!s || start >= ft_strlen(s))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	trimlen = ft_strlen(s + start);
	if (ft_strlen(s) < start)
		len = 0;
	if (trimlen < len)
		len = trimlen;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

char *ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char *ft_strdup(const char *s)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

static char *extract(char *line)
{
	size_t count;
	char *backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}
static char *function_name(int fd, char *buf, char *backup)
{
	int read_line;
	char *char_temp;

	read_line = 1;
	while (1)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		else
		{
			char_temp = backup;
			backup = ft_strjoin(backup, buf);
			// free(char_temp);
		}
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (backup);
}

char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = function_name(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}

int main(void)
{
	int fd;
	char *line;
	fd = open("shortLines.txt", O_RDONLY);
	int i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("\tLine number: %d\t%s\n\n\n", i, line);
		free(line);
		i++;
	}
	printf("End of file reached\n");
	close(fd);
	return (0);
}
