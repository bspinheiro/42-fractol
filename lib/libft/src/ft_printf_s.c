/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:24:50 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 10:31:09 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_arg_s(int *counter, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	*counter += ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (*counter);
}
