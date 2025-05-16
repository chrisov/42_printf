/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:57:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/22 16:10:08 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

#include "libft/inc/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printunbr_fd(int n, int fd);
int		ft_printxxnbr_fd(unsigned int n, int fd);
int		ft_printxnbr_fd(unsigned int n, int fd);
int		ft_printstr_fd(char *s, int fd);
int		ft_printnbr_fd(int n, int fd);
int		ft_printchar_fd(char c, int fd);
int		ft_printptr_fd(void	*ptr, int fd);
size_t	ft_strlen(const char *str);

#endif