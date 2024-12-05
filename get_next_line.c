/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:46:53 by moel-yag          #+#    #+#             */
/*   Updated: 2024/12/04 20:46:58 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_readfile(int fd, char *str, char *buf)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (ret > 0 &&!ft_strchr(str, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		temp = ft_strjoin(str, buf);
		free(str);
		str = temp;
	}
	return (str);
}

char	*ft_freeline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (str[i])
		str = ft_substr(str, i + 1, ft_strlen(str) - i);
	else
		str = ft_calloc(1, sizeof(char));
	free(str);
	return (line);
}

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readfile(fd, str, buf);
	free(buf);
	if (!str)
		return (NULL);
	line = ft_freeline(str);
	return (line);
}
