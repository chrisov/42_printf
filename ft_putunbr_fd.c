/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:01:58 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/19 15:55:01 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_div(unsigned int num)
{
	int				res;
	unsigned int	i;

	res = 1;
	i = 1;
	while (i <= num / 10)
	{
		res *= 10;
		i *= 10;
	}
	return (res);
}

void	ft_putunbr_fd(int n, int fd)
{
	char			num;
	int				div;
	int				digit;
	unsigned int	un;

	un = (unsigned int)n;
	div = ft_div(un);
	while (div > 0)
	{
		digit = un / div;
		num = digit + '0';
		write(fd, &num, 1);
		un %= div;
		div /= 10;
	}
}
// int	main(void)
// {
// 	printf("custom casting: ");
// 	ft_putunbr_fd(-42, 1);
// 	printf("\noriginal casting: \"%u\'\n", -42);
// 	return (0);
// }