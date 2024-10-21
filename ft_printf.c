/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/21 10:35:47 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str ++;
			if (*str == 'c' || *str == '%')
				count += ft_putchar_fd((char)va_arg(args, int), 1);
			if (*str == 'i' || *str == 'd' )
				count += ft_putnbr_fd(va_arg(args, int), 1);
			if (*str == 's')
				count += ft_putstr_fd((char *)va_arg(args, int *), 1);
			if (*str == 'u')
				count += ft_putunbr_fd(va_arg(args, int), 1);
			if (*str == 'x')
				count += ft_putxnbr_fd(va_arg(args, int), 1);
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
// 		// char	*str = "Hello World";
// 		// char	c = 'E';
// 		// char	prc = '%';
// 		int		n = 42;
// 		// int		count;
//
// 	ft_printf("\nft_printf: %x\n", n);
// 	printf("count: %i\n", printf("printf: %x\n\n", n));
// 	return (0);
// }
