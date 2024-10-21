/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/21 11:37:12 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rev_str(char *str, int i)
{
	int		j;
	char	temp;

	j = 0;
	while (j < i / 2)
	{
		temp = *(str + j);
		*(str + j) = *(str + i - j -1);
		*(str + i - j - 1) = temp;
		j++;
	}
}

int	ft_putxnbr_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	char	hex_str[20];
	int		remainder;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n == 0)
		hex_str[count++] = '0';
	else
	{
		while (n > 0)
		{
			remainder = n % 16;
			hex_str[count++] = hex_digits[remainder];
			n /= 16;
		}
	}
	hex_str[count] = '\0';
	ft_rev_str(hex_str, count);
	ft_putstr_fd(hex_str, fd);
	return (count);
}
