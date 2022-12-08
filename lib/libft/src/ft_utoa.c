/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:13:22 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/30 00:40:35 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	long int	nb;
	size_t		l;
	char		*str;

	nb = n;
	l = ft_nbrlen(n, 10) - 1;
	str = ft_calloc(ft_nbrlen(n, 10) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
