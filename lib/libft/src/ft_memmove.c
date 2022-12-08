/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:41:59 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:41:27 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*_dst;
	const unsigned char	*_src;

	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	if (_dst <= _src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
		{
			*(_dst + len) = *(_src + len);
		}
	}
	return (dst);
}
