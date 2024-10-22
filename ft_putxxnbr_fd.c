/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxxnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 13:46:52 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_alloc(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	ft_rev_str(char *str, int i, int fd)
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
	ft_putstr_fd(str, fd);
}

int	ft_putxxnbr_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	char	*hex_str;
	int		remainder;
	int		count;

	hex_digits = "0123456789ABCDEF";
	hex_str = malloc(ft_alloc(n) + 2);
	if (hex_str == NULL)
		return (0);
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
	ft_rev_str(hex_str, count, fd);
	free(hex_str);
	return (count);
}
