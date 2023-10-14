
#include "get_next_line.h"

// void clean_gnl(char *line, char *buffer)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (line[i] && line[i] != 10)
// 		i++;
// 	if (line[i] == 10)
// 		i++;
// 	while (line[i])
// 	{
// 		buffer[j] = line[i];
// 		line[i] = 0;
// 		i++;
// 		j++;
// 	}
// 	buffer[j] = 0;
// }

// char *get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE + 1];
// 	char *line;
// 	int byte_read;

// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	line = 0;
// 	line = ft_join_gnl(line, buffer);
// 	byte_read = 1;
// 	while (byte_read > 0 && !strchr_gnl(line, 10))
// 	{
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			for (int i = 0; i < BUFFER_SIZE; i++)
// 				buffer[i] = 0;
// 			return (free(line), NULL);
// 		}
// 		if (byte_read < 0)
// 			return (free(line), NULL);
// 		buffer[byte_read] = 0;
// 		line = ft_join_gnl(line, buffer);
// 	}
// 	if (!line[0])
// 		return (free(line), NULL);
// 	else
// 		clean_gnl(line, buffer);
// 	return (line);
// }

// // int main(void)
// // {
// // 	int fd;
// // 	char *line;
// // 	fd = open("input.txt", O_RDONLY);
// // 	int i = 1;
// // 	while ((line = get_next_line(fd)))
// // 	{
// // 		printf("\tLine number: %d\t%s\n\n\n", i, line);
// // 		free(line);
// // 		i++;
// // 	}
// // 	printf("End of file reached\n");
// // 	close(fd);
// // 	return (0);
// // }

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
			return (NULL);
		else if (read_line == 0)
			break;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(backup, buf);
		free(char_temp);
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (backup);
}

char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *backup=NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = function_name(fd, buf, backup);
	// if (!line)
	// {
	// 	free(backup);
	// 	backup = NULL;
	// }
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
