

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define FD_LIMIT 256
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);

#endif