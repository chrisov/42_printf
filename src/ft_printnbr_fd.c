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

#include "../inc/ft_printf.h"

/**
 * @brief Displays the integer passed as the parameter to the fd.
 * 
 * @returns The number of the characters displayed (length of the number).
 */
int	ft_printnbr_fd(int n, int fd)
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
			count += ft_printchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			count += ft_printnbr_fd(n / 10, fd);
		count += ft_printchar_fd((n % 10) + '0', fd);
	}
	return (count);
}
