#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	char	*q;
	size_t	i;

	p = (char *)dst;
	q = (char *)src;
	if (p == q)
		return (p);
	i = 0;
	while (i < n)
	{
		*(p + i) = *(q + i);
		i++;
	}
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (NULL);
	ft_memcpy (p, (char *) s1, len_s1);
	ft_memcpy (p + len_s1, s2, len_s2);
	p[len_s1 + len_s2] = 0;
	free(s1);
	// free(s2);
	return (p);
}

int ft_strlen(char *s)
{
	int i ;

	// if (!s)
	// 	return (-1);
	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(char *todup)
{
	char	*q;
	size_t	n;

	n = 0;
	q = (char *)malloc(ft_strlen(todup) + 1);
	if (!q)
		return (NULL);
	while (todup[n])
	{
		q[n] = todup[n];
		n++;
	}
	q[n] = '\0';
	return (q);
}