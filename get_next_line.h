#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 191041445
#endif
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int     ft_strfind(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *todup);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
int ft_strlenght(char *str);

char	*get_next_line(int fd);

#endif