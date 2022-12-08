/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:42:18 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 09:24:21 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dc(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		l;
	char		*str;

	nb = n;
	l = ft_dc(nb) - 1;
	str = ft_calloc(ft_dc(nb) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
