#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_strlen(const char *str); int strchr_gnl(char *s, char x);
char *ft_join_gnl(char *s1, char *s2);
char *get_next_line(int fd); void clean_gnl(char *line, char *buffer);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int i);
char *ft_substr(char const *s, unsigned int start, size_t len);
#endif