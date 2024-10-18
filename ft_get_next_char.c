/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:06:46 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/18 18:01:20 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_get_next_char(const char *str)
{
	str++;
	if (*str == 'c')
		write(1, "char type", 9);
	if (*str == 'd' || *str == 'i')
		ft_putnbr_fd();
	if (*str == 's')
		write(1, "str type", 8);
	if (*str == 'p')
		write(1, "ptr type", 8);
	if (*str == 'u')
		write(1, "unsigned decimal type", 21);
	return (str);
}
