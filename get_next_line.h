/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:44:57 by mboutuil          #+#    #+#             */
/*   Updated: 2023/01/31 15:33:50 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
#include<fcntl.h>
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 188
#endif
char	*get_next_line(int fd);
int     jumps_checker(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_rest(char *s);
char	*get_line(char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *todup);

#endif