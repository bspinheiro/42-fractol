/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:45 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:30 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	map = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = (*f)(i, s[i]);
		++i;
	}
	map[i] = '\0';
	return (map);
}
