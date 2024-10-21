/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/21 22:48:33 by dimitris         ###   ########.fr       */
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

int	ft_putxnbr_fd(unsigned long n, int fd)
{
	char	*hex_digits;
	char	hex_str[20];			//  <--- this needs changing into
	int		remainder;				//a pointer so the hex value should
	int		count;					//be calculated sooner

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

// int	main(void)
// {
// 	int	l = INT_MIN;
// 	ft_putxnbr_fd(l, 1);
// 	return (0);
// }