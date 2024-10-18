/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:50:05 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/17 18:10:45 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	d;

	ptr = (char *)s;
	d = (char)c;
	while (*ptr != '\0')
	{
		if (*ptr == d)
			return (ptr);
		ptr++;
	}
	if (d == '\0')
		return (ptr);
	return (0);
}
