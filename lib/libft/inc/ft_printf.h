/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:11:48 by bda-silv          #+#    #+#             */
/*   Updated: 2022/10/31 14:56:17 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	f_arg_c(int *counter, va_list ap);
int	f_arg_s(int *counter, va_list ap);
int	f_arg_di(int *counter, va_list ap);
int	f_arg_u(int *counter, va_list ap);
int	f_arg_p(int *counter, va_list ap);
int	f_arg_x(int isupper, int *counter, va_list ap);
int	f_arg_pc(int *counter);

#endif
