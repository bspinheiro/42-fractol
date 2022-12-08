/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:24 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:55:07 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	n_needle;

	n_needle = ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)hay);
	i = 0;
	while (*hay && i < n)
	{
		if ((ft_strncmp(hay, needle, n_needle) == 0) && (i + n_needle <= n))
			return ((char *)hay);
		hay++;
		i++;
	}
	return (0);
}
