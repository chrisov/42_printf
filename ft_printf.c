/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/21 22:45:24 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str ++;
			if (*str == 'c')
				count += ft_putchar_fd((char)va_arg(args, int), 1);
			if (*str == 's')
				count += ft_putstr_fd((char *)va_arg(args, int *), 1);
			if (*str == 'i' || *str == 'd' )
				count += ft_putnbr_fd(va_arg(args, int), 1);
			if (*str == 'u')
				count += ft_putunbr_fd(va_arg(args, int), 1);
			if (*str == 'x')
				count += ft_putxnbr_fd(va_arg(args, unsigned long), 1);
			if (*str == 'X')
				count += ft_putxxnbr_fd(va_arg(args, unsigned int), 1);
			if (*str == 'p')
				count += ft_putptr_fd(va_arg(args, void *), 1);
			if (*str == '%')
				count += ft_putchar_fd('%', 1);
		}
		else
			count += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int count;
// 	char	c = '%';
	
// 	count = printf(" %c ", c);
// 	printf("%d\n", count);
// 	count =	ft_printf(" %c ", c);
// 	printf("%d\n", count);
// 	return (0);
// }
