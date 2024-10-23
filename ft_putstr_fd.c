/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:10 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/23 12:01:58 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		count = write(fd, "(null)", 6);
		return (count);
	}
	while (i < ft_strlen(s))
	{
		count += ft_putchar_fd(s[i], fd);
		if (count == -1)
			return (-1);
		i++;
	}
	return (ft_strlen(s));
}
