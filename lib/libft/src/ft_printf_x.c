/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:12:48 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 09:49:35 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_arg_x(int isupper, int *counter, va_list ap)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if (isupper == 1)
	{
		while (s[i])
		{
			s[i] = ft_toupper((char)s[i]);
			i++;
		}
	}
	*counter += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (*counter);
}
