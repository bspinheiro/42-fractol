/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:16:53 by bda-silv          #+#    #+#             */
/*   Updated: 2022/11/01 10:40:33 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*first_part_of(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s[i] == 0)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = ft_calloc(1, (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*second_part_of(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	if (s[i] == 0)
	{
		free(s);
		return (NULL);
	}
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	j = i;
	while (s[i] != '\0')
		i++;
	len = (i - j);
	str = ft_calloc(1, len);
	i = 0;
	j++;
	while (i < len)
		str[i++] = s[j++];
	free(s);
	return (str);
}

char	*build_line(int fd, char *cache)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	while (bytes != 0 && !ft_strchr(cache, '\n'))
	{
		buffer = ft_calloc(1, (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		cache = ft_strjoinfree(cache, buffer);
		free(buffer);
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = build_line(fd, cache);
	if (!cache)
		return (NULL);
	line = first_part_of(cache);
	cache = second_part_of(cache);
	return (line);
}
