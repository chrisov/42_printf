/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:57:23 by dchrysov          #+#    #+#             */
/*   Updated: 2024/10/21 16:44:48 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putunbr_fd(int n, int fd);
int		ft_putxxnbr_fd(unsigned int n, int fd);
int		ft_putxnbr_fd(unsigned int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putptr_fd(void	*ptr, int fd);
size_t	ft_strlen(const char *str);

#endif