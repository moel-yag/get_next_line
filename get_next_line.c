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

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*line;
	char		*temp;
	int			read_size;

	line = ft_calloc(1, sizeof(char));
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(line, buf);
		free(line);
		line = temp;
		if (ft_strchr(line, '\n'))
			break ;
	}
	if (read_size < 0)
		return (NULL);
	if (read_size == 0 && ft_strlen(line) == 0)
		return (NULL);
	temp = ft_strchr(line, '\n');
	if (temp)
	{
		*temp = '\0';
		temp++;
	}
	return (line);
}
