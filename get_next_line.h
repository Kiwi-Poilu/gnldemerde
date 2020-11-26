/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:32:13 by sobouatt          #+#    #+#             */
/*   Updated: 2020/11/26 21:35:47 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 14
#endif

#include <stdio.h>
#include <unistd.h>
#include <libc.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
