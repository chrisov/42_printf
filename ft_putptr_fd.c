/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:46:09 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 12:14:02 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_putptr_fd(void	*ptr, int fd)
{
	unsigned long	address;
	char			*hex_digits;
	int				i;
	int				count;
	char			*str;

	i = 0;
	count = 0;
	address = (unsigned long)ptr;
	hex_digits = "0123456789abcdef";
	if (ptr == NULL)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	i = 2 * sizeof(address) - 2;
	str = malloc(i);
	if (str == NULL)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[i] = '\0';
	count = 2;
	while (i > 2)
	{
		str[--i] = hex_digits[address % 16];
		address /= 16;
		count++;
	}
	ft_putstr_fd(str, fd);
	free(str);
	return (count + 2);
}


// int	main(void)
// {
// 	int		l = INT_MIN;
// 	int		count;
// 	void	*ptr;

// 	ptr = &l;
// 	count = ft_putptr_fd(ptr, 1);
// 	printf("\tcount= %d\noriginal: ", count);
// 	count = printf("\n%p\n", ptr);
// 	printf("\tcount= %d\n\n", count);
// 	return (0);
// }