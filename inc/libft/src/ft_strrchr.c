/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:13:22 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/17 18:12:09 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	char		d;

	d = (char)c;
	ptr = s + ft_strlen(s) - 1;
	if (d == '\0')
		return ((char *)(ptr + 1));
	while (*s)
	{
		if (*ptr == d)
			return ((char *)ptr);
		ptr--;
		s++;
	}
	return (NULL);
}
