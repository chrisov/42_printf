/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 21:07:52 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ifcase(char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	if (*s == 's')
		count += ft_putstr_fd((char *)va_arg(args, int *), 1);
	if (*s == 'i' || *s == 'd' )
		count += ft_putnbr_fd(va_arg(args, int), 1);
	if (*s == 'u')
		count += ft_putunbr_fd(va_arg(args, int), 1);
	if (*s == 'x')
		count += ft_putxnbr_fd(va_arg(args, unsigned long), 1);
	if (*s == 'X')
		count += ft_putxxnbr_fd(va_arg(args, unsigned int), 1);
	if (*s == 'p')
		count += ft_putptr_fd(va_arg(args, void *), 1);
	if (*s == '%')
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
