/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:44 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/17 19:21:07 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*res;
	size_t		len;

	len = 0;
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, start, len + 1);
	return (res);
}
