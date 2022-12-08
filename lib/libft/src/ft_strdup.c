/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:19:27 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/09 12:24:45 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*t;

	l = ft_strlen((char *)s);
	t = malloc(sizeof(char) * (l + 1));
	if (t == NULL)
		return (NULL);
	ft_memcpy(t, s, l);
	t[l] = '\0';
	return (t);
}
