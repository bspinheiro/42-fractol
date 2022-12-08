/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:39:37 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/17 11:33:30 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (((*(s + 1) == c) || (*(s + 1) == 0)) && (*s != c))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(wc(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (j != i)
			str[k++] = ft_substr(s, j, i - j);
	}
	free(str[k]);
	return (str);
}
