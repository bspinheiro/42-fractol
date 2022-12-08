/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:31:37 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:40:28 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (((char *)dst) == ((char *)src) && n > 0)
		return (0);
	else
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
		return (dst);
	}
}
