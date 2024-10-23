/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/23 15:47:33 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putxnbr_fd(unsigned int n, int fd)
{
	unsigned long	remainder;
	char			*hex_digits;
	int				count;

	count = 0;
	remainder = 1;
	hex_digits = "0123456789abcdef";
	while (n / remainder >= 16)
		remainder *= 16;
	while (remainder != 0)
	{
		count += write(fd, &hex_digits[(n / remainder) % 16], 1);
		if (count == -1)
			return (count);
		remainder /= 16;
	}
	return (count);
}
