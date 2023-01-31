/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:40:22 by mboutuil          #+#    #+#             */
/*   Updated: 2023/01/31 15:45:10 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	jumps_checker(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] != '\n')
			return (1);
	return (0);
}

char	*get_rest(char *s)
{
	int		st;
	int		e;
	char	*sub;
// leaks
	if (!s)
		return (NULL);
	e = ft_strlen(s);
	st = 1;

	while (s[st] && s[st] != '\n')
		st++;
	if (s[st] == '\n')
		sub = ft_substr(s, st, e - st);
	// printf("sub = %s\n", sub);
	return (sub);
}

char	*get_line(char *s)
{
	int		i;
	char	*sub;

	i = 0;
	// printf("sub = %s\n", s);
	while (s[++i])
		if (s[i] == '\n')
			break;
	sub = ft_substr(s, 0, i + 1);
	return (sub);
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*re;
	static char	*hold;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	i = 1;
	while (i && !ft_strchr(hold, '\n'))
	{
		re = (char *) malloc(BUFFER_SIZE + 1);
		if (!re)
			return (NULL);
		j = read(fd, re, BUFFER_SIZE);
		if (j < 0)
			return (free(re), NULL);		
		// if (!re)
		// 	return (free(re), NULL);
		re[j] = '\0';
		hold = ft_strjoin(hold, re);
		free(re);
		// printf("\nhey\n");
		// if (ft_strchr(hold, '\n'))
		// 	break;
	}
	s = get_line(hold);
	hold = get_rest(hold);
	return (s);
}

int main()
{
	int fd;

	fd = open("j.txt",O_RDONLY);
	char *p;
	// p = get_next_line(fd);
	// printf("%s", p);

	// p = get_next_line(fd);
	// printf("%s", p);
	// p = get_next_line(fd);
	// printf("%s", p);
	while ((p = get_next_line(fd)))
		{
			printf("%s", p);
			sleep(1);
		}
}