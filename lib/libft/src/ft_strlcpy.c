/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 07:31:21 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:47:54 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	const char	*buf;

	if (!dst || !src)
		return (ft_strlen(src));
	buf = src;
	if (src && dst && dstlen)
	{
		while (*src && --dstlen)
			*dst++ = *src++;
		*dst = 0;
	}
	return (ft_strlen((char *)buf));
}
