/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:01:58 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/23 15:42:32 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_fd(int n, int fd)
{
	int				count;
	unsigned int	un;

	count = 0;
	un = (unsigned int)n;
	if (un >= 10)
	{
		count += ft_putunbr_fd(un / 10, fd);
		if (count == -1)
			return (count);
	}
	count += ft_putchar_fd((un % 10) + '0', fd);
	return (count);
}
