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
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

char	*ft_readfile(int fd, char *str, char *buf)
{
	int		ret;
	char	*temp;

	ret = 1;
	if (!str)
		str = ft_strdup("");
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
		temp = ft_strjoin(str, buf);
		free(str);
		if (!temp)
			return (NULL);
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
		str = malloc(ft_strlen(str) + 1);
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readfile(fd, str, buf);
	free(buf);
	if (!str)
		return (NULL);
	line = ft_freeline(str);
	return (line);
}
