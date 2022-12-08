/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:29:54 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:55:29 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	if (c == 0)
		return (ft_strchr(s, c));
	save = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			save = (char *)s;
		s++;
	}
	return (save);
}
