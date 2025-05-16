/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitris <dimitris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:10 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 20:33:33 by dimitris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Displays a string to the fd.abort
 * 
 * @returns The number of the characters displayed.
 */
int	ft_printstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (i < ft_strlen(s) && count != -1)
	{
		count += ft_printchar_fd(s[i], fd);
		i++;
	}
	return (ft_strlen(s));
}
