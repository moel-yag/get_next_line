/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:36:52 by moel-yag          #+#    #+#             */
/*   Updated: 2024/12/19 16:51:26 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

ssize_t	ft_index_nl(const char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_freeline(char **str)
{
	char	*line;
	char	*temp;
	int		i;

	if (*str[0] == '\0')
	{
		free(*str);
		return (*str = NULL);
	}
	i = ft_index_nl(*str);
	line = ft_substr(*str, 0, i + 1);
	if (i < 0 && line != NULL)
	{
		temp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
		if (!temp)
		{
			free(line);
			line = NULL;
		}
	}
	else
		temp = NULL;
	free(*str);
	*str = temp;
	return (line);
}

char	*ft_readfile(int fd, char *str, char *buf)
{
	int	ret;

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
	static char	*str[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(str[fd]);
		return (str[fd] = NULL);
	}
	str[fd] = ft_readfile(fd, str[fd], buf);
	free(buf);
	if (!str[fd])
		return (NULL);
	line = ft_freeline(&str[fd]);
	return (line);
}
