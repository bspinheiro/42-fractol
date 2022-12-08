/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:31:45 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:47:35 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstlen)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(dst + i) && i < dstlen)
		i++;
	j = 0;
	while (*(src + j) && (i + j + 1) < dstlen)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i < dstlen)
		*(dst + i + j) = 0;
	return (i + ft_strlen(src));
}
