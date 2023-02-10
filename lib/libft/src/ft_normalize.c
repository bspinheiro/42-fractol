/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:09:43 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 19:39:05 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** ft_normalize:
 ** 	Streamline lowercase argv inputs
*/

void	ft_normalize(char **argv)
{
	int	i;
	int	p;

	p = 0;
	while (argv[++p])
		;
	p = p - 1;
	while (p != 0)
	{
		i = 0;
		while (argv[p][i])
		{
			argv[p][i] = ft_tolower(argv[p][i]);
			i++;
		}
		p--;
	}
}
