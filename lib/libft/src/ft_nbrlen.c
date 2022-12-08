/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:13:59 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 09:27:55 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(unsigned long long n, unsigned int base)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
