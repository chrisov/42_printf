/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:45:20 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/23 15:38:02 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		count += write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			count += ft_putchar_fd('-', fd);
			if (count == -1)
				return (count);
			n *= -1;
		}
		if (n > 9)
		{
			count += ft_putnbr_fd(n / 10, fd);
			if (count == -1)
				return (count);
		}
		count += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (count);
}
