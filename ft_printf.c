/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 16:37:19 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ifcase(char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (*s == 's')
		count += ft_putstr_fd((char *)va_arg(args, int *), 1);
	else if (*s == 'i' || *s == 'd' )
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (*s == 'u')
		count += ft_putunbr_fd(va_arg(args, int), 1);
	else if (*s == 'x')
		count += ft_putxnbr_fd(va_arg(args, unsigned long), 1);
	else if (*s == 'X')
		count += ft_putxxnbr_fd(va_arg(args, unsigned int), 1);
	else if (*s == 'p')
		count += ft_putptr_fd(va_arg(args, void *), 1);
	else if (*s == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str && count != -1)
	{
		if (*str == '%')
		{
			str++;
			count += ft_ifcase((char *)str, args);
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

// 	count = printf("\"\001\"\002\"\007\"\v\"\010\"\f\"\r\"\n\"");
// 	printf("%d\n", count);
// 	count =	ft_printf("\"\001\"\002\"\007\"\v\"\010\"\f\"\r\"\n\"");
// 	printf("%d\n", count);
// 	return (0);
// }
