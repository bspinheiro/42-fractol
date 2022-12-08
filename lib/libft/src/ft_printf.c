/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:27:17 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/04 10:40:01 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse(char c, int *counter, va_list ap)
{
	if (c == 'c')
		f_arg_c(counter, ap);
	if (c == 's')
		f_arg_s(counter, ap);
	if (c == 'd')
		f_arg_di(counter, ap);
	if (c == 'i')
		f_arg_di(counter, ap);
	if (c == 'u')
		f_arg_u(counter, ap);
	if (c == 'p')
		f_arg_p(counter, ap);
	if (c == '%')
		f_arg_pc(counter);
	if (c == 'x')
		f_arg_x(0, counter, ap);
	if (c == 'X')
		f_arg_x(1, counter, ap);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start (ap, str);
	if (!str)
		return (counter);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && *ft_strchr("cspdiuxX%", str[i + 1]))
			ft_parse(str[++i], &counter, ap);
		else
		{
			counter++;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end (ap);
	return (counter);
}
