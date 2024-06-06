/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:51:25 by edegarci          #+#    #+#             */
/*   Updated: 2024/06/06 12:58:24 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

int			ft_putchar(char c);
int			ft_putnbr_base(unsigned int n, char *base);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr(int n);
int			ft_putptr(void *ptr);
int			ft_putstr(char *s);
char		*ft_strchr(const char *s, int c);
int			ft_format(va_list data, char c);
int			type_var(char c, va_list data);
int			ft_printf(char const *str, ...);

#endif
