/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:17 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/17 18:56:16 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalnum(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}
