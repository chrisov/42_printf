/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:00:01 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/17 19:11:27 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	index;

	index = 0;
	res = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	while (index < ft_strlen(s))
	{
		res[index] = f(index, *(s + index));
		index++;
	}
	res[index] = '\0';
	return (res);
}
