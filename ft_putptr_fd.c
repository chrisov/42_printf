/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:46:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 21:05:59 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mem_size(unsigned long n)
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
		*(str + j) = *(str + i - j - 1);
		*(str + i - j - 1) = temp;
		j++;
	}
	ft_putstr_fd(str, fd);
}

static char	*ft_alloc(char *str, unsigned long n)
{
	str = malloc(ft_mem_size(n) + 4);
	if (str == NULL)
		return (NULL);
	return (str);
}

static int	ft_putlxnbr_fd(unsigned long n, char *str, int fd)
{
	char	*hex_digits;
	int		remainder;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	else
	{
		while (n > 0)
		{
			remainder = n % 16;
			str[count++] = hex_digits[remainder];
			n /= 16;
		}
	}
	str[count++] = 'x';
	str[count++] = '0';
	str[count] = '\0';
	ft_rev_str(str, ft_strlen(str), fd);
	return (count);
}

int	ft_putptr_fd(void	*ptr, int fd)
{
	char			*hex_str;
	int				count;

	hex_str = NULL;
	hex_str = ft_alloc(hex_str, (unsigned long)ptr);
	count = ft_putlxnbr_fd((unsigned long)ptr, hex_str, fd);
	free(hex_str);
	return (count);
}
