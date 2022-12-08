/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:37:29 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 09:52:24 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int n, unsigned int base)
{
	char		*b;
	int			len;
	char		*str;

	if (base <= 0)
		return (NULL);
	len = ft_nbrlen(n, base);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	b = ft_substr("0123456789abcdefghijklmnopqrstuvwxyz", 0, base);
	if (!b)
		return (NULL);
	if (n == 0)
		str[0] = b[0];
	while (len > 0)
	{
		str[--len] = b[n % base];
		n /= base;
	}
	if (b)
		free(b);
	return (str);
}
