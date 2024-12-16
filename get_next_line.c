/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:46:53 by moel-yag          #+#    #+#             */
/*   Updated: 2024/12/15 21:12:51 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((char)c != s[i])
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

size_t	ft_findchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_freeline(char **str)
{
	char	*line;
	char	*temp;
	int		i;

	if (*str[0] == '\0')
	{
		free(*str);
		return (NULL);
	}
	i = ft_findchr(*str, '\n');
	line = ft_substr(*str, 0, i + 1);
	if ((*str)[i] && line)
	{
		temp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
		if (!temp)
			line = NULL;
	}
	else
		temp = NULL;
	free(*str);
	*str = temp;
	return (line);
}

char	*ft_readfile(int fd, char *str, char *buf)
{
	int		ret;

	ret = 1;
	while (ret > 0 && !ft_strchr(str, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(str);
			return (NULL);
		}
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	str = ft_readfile(fd, str, buf);
	free(buf);
	if (!str)
		return (NULL);
	line = ft_freeline(&str);
	return (line);
}
