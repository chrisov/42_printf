/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:45:20 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/19 23:23:18 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		count = 11;
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			count += ft_putnbr_fd(n / 10, fd);
		count += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (count);
}
