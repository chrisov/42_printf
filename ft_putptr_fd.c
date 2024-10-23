/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:46:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/23 14:37:58 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void	*ptr, int fd)
{
	unsigned long	n;
	unsigned long	remainder;
	unsigned long	count;
	char			*hex_digits;

	count = 0;
	n = (unsigned long)ptr;
	remainder = 1;
	hex_digits = "0123456789abcdef";
	if (write(fd, "0x", 2) == -1)
		return (-1);
	count += 2;
	while (n / remainder >= 16)
		remainder *= 16;
	while (remainder != 0)
	{
		count += write(fd, &hex_digits[(n / remainder) % 16], 1);
		remainder /= 16;
	}
	return ((int)count);
}
