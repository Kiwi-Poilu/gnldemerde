/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:35:13 by sobouatt          #+#    #+#             */
/*   Updated: 2020/11/26 22:36:56 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_end(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		where(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	static int		i = 0;
	char			*buffer;
	int				read_rt;

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!line || fd < 0 || (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (check_end(str) == 0 && (read_rt = read(fd, buffer, BUFFER_SIZE)))
	{
		if (read_rt == -1)
			return (read_rt);
		buffer[read_rt] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (read_rt == 0 && i == 0)
	{
		*line = "\0";
		return (0);
	}
	i++;
	free(buffer);
	if (check_end(str) == 0)
	{
		*line = str;
		str = NULL;
		return (0);
	}
	*line = ft_substr(str, 0, where(str));
	if (str)
		str = ft_substr(str, where(str) + 1, ft_strlen(str));
	return (1);
}
/*
int                main()
{
	char *line;
	int fd;
	int i = 0;

	fd = open("empty", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%d = [%s]\n",i++, line);	
	printf("%d = [%s]\n",i, line);

	close(fd);
}
*/
