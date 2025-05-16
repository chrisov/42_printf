/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 13:46:43 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Calculates the length of the hex representation of the number passed
 * as parameter
 */
static int	hex_length(unsigned long n)
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

/**
 * @brief Reverses the string and displays the result.
 * 
 * @param str Pointer to the string to be reversed.
 * @param length Length of the string to be reversed.
 */
static void	ft_rev_str(char *str, int length, int fd)
{
	int		j;
	char	temp;

	j = 0;
	while (j < length / 2)
	{
		temp = *(str + j);
		*(str + j) = *(str + length - j - 1);
		*(str + length - j - 1) = temp;
		j++;
	}
	ft_putstr_fd(str, fd);
}

/**
 * @brief Converts an unsigned int number to its hex representation and
 * displays the result.
 * 
 * @param n The number to be converted.
 * @returns The number of the characters displayed (length of the number).
 * 
 * @note Last step is to reverse the resulting string since it's stored
 * from end to start.
 */
int	ft_printxnbr_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	char	*hex_str;
	int		remainder;
	int		count;

	hex_digits = "0123456789abcdef";
	hex_str = malloc(hex_length(n) + 2);
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
