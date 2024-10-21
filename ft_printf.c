/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/19 16:42:27 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c' || *(str + 1) == '%')
				ft_putchar_fd((char)va_arg(args, int), 1);
			if (*(str + 1) == 'i' || *(str + 1) == 'd' )
				ft_putnbr_fd(va_arg(args, int), 1);
			if (*(str + 1) == 's')
				ft_putstr_fd((char *)va_arg(args, int *), 1);
			if (*(str + 1) == 'u')
				ft_putunbr_fd(va_arg(args, int), 1);
			str ++;
		}
		else
			write(STDOUT_FILENO, &(*str), 1);
		str++;
	}
	va_end(args);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "Hello World";
// 	char	c = 'D';
// 	char	prc = '%';
// 	int		n = -42;

// 	ft_printf("\nMy char is \"%c\" ...!\n", c);
// 	ft_printf("My percentage sign is \"%c\" ...!\n", prc);
// 	ft_printf("My phrase is \"%s\" ...!\n", str);
// 	ft_printf("My integer is \"%i\" ...!\n", n);
// 	ft_printf("My double is \"%d\" ...!\n", n);
// 	ft_printf("My unsigned int is \"%u\" ...!\n", n);
// 	printf("\nCheck unsigned: \"%u\"\n\n", n);
// 	return (0);
// }
