
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <fcntl.h>
#include <stdio.h>
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

int		ft_strchr(const char *str, int c);
char	*ft_strjoin(char  *s1, char  *s2);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *s);

#endif