/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:16:11 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/30 01:39:56 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_arg_u(int *counter, va_list ap)
{
	char	*s;

	s = ft_utoa(va_arg(ap, unsigned int));
	*counter += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (*counter);
}
