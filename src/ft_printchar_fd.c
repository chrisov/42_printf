/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:41:10 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 16:38:27 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Displays a single character in the specified fd.abort
 * 
 * @returns 1 (number of char displayed) if successfull, -1 otherwise
 */
int	ft_printchar_fd(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}
