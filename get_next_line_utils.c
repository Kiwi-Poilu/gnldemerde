#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strdup(char *str)
{
	int        i;
	char    *res;

	i = 0;
	if (!str)
	{
		if (!(res = malloc(sizeof(char))))
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    *ft_strjoin(char *str, char *buf)
{
    int        i;
    char    *res;

    i = -1;
    if (!str)
        return (ft_strdup(buf));
    if (!(res = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1))))
        return (NULL);
    while (str[++i])
        res[i] = str[i];
    while (*buf)
        res[i++] = *buf++;
    res[i] = '\0';
    free(str);
    return (res);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char            *res;
	unsigned int    i;

	i = 0;
	if ((int)start > ft_strlen((char *)s))
	{
		if (!(res = malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
