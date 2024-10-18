/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/18 17:53:03 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_get_next_char(str, va_arg(args, char));
			str ++;
		}
		else
			write(STDOUT_FILENO, &(*str), 1);
		str++;
	}
	va_end(args);
	return (0);

}

#include <stdio.h>
int	main(void)
{
	ft_printf("My number is %p ...!\n");
	return (0);
}
