/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:56 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 10:31:45 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_arg_p(int *counter, va_list ap)
{
	char	*adr;
	char	*s;

	adr = ft_ultoa_base(va_arg(ap, unsigned long), 16);
	s = ft_strjoin("0x", adr);
	*counter += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	if (adr)
		free(adr);
	return (*counter);
}
