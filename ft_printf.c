/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/19 23:30:22 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Not handling errors
 */
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
			if (*str == 'c')
				count += ft_putchar_fd((char)va_arg(args, int), 1);
			if (*str == 'i' || *str == 'd' )
				count += ft_putnbr_fd(va_arg(args, int), 1);
			if (*str == 's')
				count += ft_putstr_fd((char *)va_arg(args, int *), 1);
			if (*str == 'u')
				count += ft_putunbr_fd(va_arg(args, int), 1);
		}
		else
		{
			write(STDOUT_FILENO, &(*str), 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main(void)
{
		// char	*str = "Hello World";
		// char	c = 'E';
		// char	prc = '%';
		// int		n = INT_MIN;
		// int		count;

	ft_printf("\n %% \n");
	printf(" %% \n\n");
	return (0);
}
