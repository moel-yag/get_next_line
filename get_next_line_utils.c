/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:47:21 by moel-yag          #+#    #+#             */
/*   Updated: 2024/12/04 20:47:22 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	size_t    len1;
    size_t    len2;
    char    *str;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc((len1 + len2 + 1) * sizeof(char));
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1, len1 + 1);
    ft_strlcpy(str + len1, s2, len2 + 1);
    return (str);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *sub;

    if (!s)
        return (NULL);
    sub = malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    ft_strlcpy(sub, s + start, len + 1);
    return (sub);
}

char    *ft_strchr(const char *s, int c)
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

char    *ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t    i;

    i = 0;
    while (i < size - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
